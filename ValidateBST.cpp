/*

Validate Binary Search Tree

Solution
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

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
    
    bool __isValidBST(TreeNode *node, long int __min, long int __max)
    {
        if (!node) return true;
        
        if (node->val <= __min || node->val >= __max) return false;
        
        bool l = __isValidBST(node->left, __min, node->val);
        if (l == false) return false;
        
        bool r = __isValidBST(node->right, node->val, __max);
        return r;
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        // Reason for supplying LONG_MIN and LONG_MAX instead of INT_MIN and INT_MAX is that
        // to handle node's value with [2147483647] which is INT_MAX
     
        return __isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    
    
    
    #if 0
    // This method will always have problem with not hanving knowledge about parents history
    // May fail when deeper node failed to follow BST  property
    
    bool __isValidBST(TreeNode *parent, TreeNode *L, TreeNode *R)
    {
        if (!parent) return true;
        
        //printf("\n P : %d L : %d R : %d", parent->val, L ? L->val : -99, R ? R->val: -99);
        
        if (L)
        {
            if (parent->val <= L->val) return false;
            if (L->left)
            {
                if (L->left->val >= L->val) return false;
            }
            if (L->right)
            {
                if (L->right->val >= parent->val) return false;
            }
        }
        
        if (R)
        {
            
            if (parent->val >= R->val) return false;
            if (R->left)
            {
                if (R->left->val <= parent->val) return false;
            }
            if (R->right)
            {
                if (R->right->val <= parent->val) return false;
            }
        }
        
        if (L)
        {
            bool l = __isValidBST(L, L->left, L->right);
            if (!l) return false;
        }
        
        if (R)
            return __isValidBST(R, R->left, R->right);
        
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        
        //check root has BST property
        if (root->left && root->val <= root->left->val) return false;
        if (root->right && root->val >= root->right->val) return false;
        
        //printf("\n Calling ...\n");
        return  __isValidBST(root, root->left, root->right);
        
            
    }
    #endif
    
};
