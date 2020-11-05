/*

530. Minimum Absolute Difference in BST
Easy

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    
    void inorder_traverse(TreeNode *root, TreeNode **prev, int &min_so_far)
    {
        if (!root) return;
        
        inorder_traverse(root->left, prev, min_so_far);
        
        // Do the work here if you have prev
        
        if(prev && *prev)
        {
            min_so_far = min(min_so_far, abs(root->val - (*prev)->val));
        }
        
        *prev = root;
        
        // Got to right 
        
        inorder_traverse(root->right, prev, min_so_far);
        
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        
        int res = INT_MAX;
        TreeNode *prev = NULL;
        
        inorder_traverse(root, &prev, res);
        
        return res;
        
        
        /*
            Success
            Details 
            Runtime: 20 ms, faster than 87.39% of C++ online submissions for Minimum Absolute Difference in BST.
            Memory Usage: 25.6 MB, less than 68.13% of C++ online submissions for Minimum Absolute Difference in BST.?
        */
        
    }
};
