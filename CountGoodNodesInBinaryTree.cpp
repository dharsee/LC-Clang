/*
Count Good Nodes in Binary Tree

Solution
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].

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
    
    void __goodNodes(TreeNode *root, int curr_max, int &count) {
        
        if (!root) { // Leaf node case
            return;            
        }
        
        if (root->val >= curr_max)
        {
            curr_max = root->val;
            count++;
        }
        
        __goodNodes(root->left, curr_max, count);
        __goodNodes(root->right, curr_max, count);
        
    }
    
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        
        if (!root) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        
        __goodNodes(root, root->val, count);
        
        return count;
    }
};


/*

Submission Detail
63 / 63 test cases passed.
Status: Accepted
Runtime: 104 ms
Memory Usage: 86.4 MB
Submitted: 0 minutes ago


*/
