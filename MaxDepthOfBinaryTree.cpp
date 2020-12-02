/*
Maximum Depth of Binary Tree

Solution
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
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
    
    void traverse(TreeNode *root, int curr_len, int &max_depth)
    {
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL)
        {
            // This is leaf node
            curr_len++;
            
            max_depth = max(max_depth, curr_len);
            
            return;
        }
        
        // Do it for both sub-trees
        
        traverse(root->left, curr_len + 1, max_depth);
        traverse(root->right, curr_len + 1, max_depth);
        
    }
    
    int maxDepth(TreeNode* root) {
    
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        
        int res = 0;
        int curr_len = 0;
        
        traverse(root, curr_len, res);
        
        return res;
        
        
        /*
        39 / 39 test cases passed.
        Status: Accepted
        Runtime: 4 ms
        Memory Usage: 19.5 MB
        Submitted: 0 minutes ago
        */
    }
};
