/*
226. Invert Binary Tree
Easy

6589

93

Add to List

Share
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    
    void __traverse(TreeNode *root) {
        
        if (!root) return;
        
        TreeNode *left = root->left; 
        TreeNode *right = root->right;
        
        root->left = right;
        root->right = left;
        
        // Do it for left and right subtrees
        
        __traverse(root->left);
        __traverse(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        __traverse(root);
        
        return root;
        
    }
};


/*

Success
Details 
Runtime: 8 ms, faster than 7.52% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.6 MB, less than 79.47% of C++ online submissions for Invert Binary Tree.


*/
