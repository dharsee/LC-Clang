/*
687. Longest Univalue Path
Easy

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int res;
public:
    
    int traverse(TreeNode *root)
    {
        if (!root) return 0;
        
        // Do it for left and right sub trees
        int l = traverse(root->left);
        int r = traverse(root->right);
        
        int left_len = 0, right_len = 0;
        
        
        // This is leaf node
        if (root->left != NULL && root->left->val == root->val)
        {
            left_len += l + 1;
        }
        
        if (root->right != NULL && root->right->val == root->val)
        {
            right_len += r + 1;
        }
        
        res = max(res, left_len + right_len);
        
        return max(left_len, right_len);
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        res = 0;
        
        traverse(root);
        
        return res;
    }
};

/*

Success
Details 
Runtime: 196 ms, faster than 56.36% of C++ online submissions for Longest Univalue Path.
Memory Usage: 72.2 MB, less than 30.79% of C++ online submissions for Longest Univalue Path.


*/
