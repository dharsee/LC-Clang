/*

House Robber III

Solution
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> helper(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        
        int rob = root->val + left[1] + right[1];
        int notRob = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {rob, notRob};
        
        
    }
    int rob(TreeNode* root) {
        
        vector<int> res = helper(root);
        
        return max(res[0], res[1]);
        
        /*
                    124 / 124 test cases passed.
            Status: Accepted
            Runtime: 32 ms
            Memory Usage: 33.5 MB
            Submitted: 0 minutes ago

        
        */
    }
};
