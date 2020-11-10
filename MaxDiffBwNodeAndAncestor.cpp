/*

Maximum Difference Between Node and Ancestor

Solution
Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105
   Hide Hint #1  
For each subtree, find the minimum value and maximum value of its descendants.

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
    
    void traverse(TreeNode *root, int minVal, int maxVal, int &res)
    {
        if (root == NULL) return;
        
        int try_res = max(abs(minVal - root->val), abs(maxVal - root->val));
        
        res = max(res, try_res);
        
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        
        traverse(root->left, minVal, maxVal, res);
        
        traverse(root->right, minVal, maxVal, res);
       
         /*
        27 / 27 test cases passed.
        Status: Accepted
        Runtime: 8 ms
        Memory Usage: 11.5 MB
        */
        
    }
    
    int traverse2(TreeNode *root, int currMin, int currMax)
    {
        if (root == NULL) return currMax - currMin;
        
        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);
        
        int left_diff = traverse2(root->left, currMin, currMax);
        int right_diff = traverse2(root->right, currMin, currMax);
        
        return max(left_diff, right_diff);
        
        /*
                    27 / 27 test cases passed.
            Status: Accepted
            Runtime: 4 ms
            Memory Usage: 11.3 MB
        */
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int res = 0;
        
        if (root == NULL) return 0;
        
        /*
        traverse(root, root->val, root->val, res);
        return res;
        */
        
        res = traverse2(root, root->val, root->val);
        return res;
        
       
    }
};
