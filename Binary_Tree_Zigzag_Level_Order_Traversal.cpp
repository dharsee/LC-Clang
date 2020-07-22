/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    
    void traverse(TreeNode *root, int level, vector<vector<int>> &res)
    {
        // BASE CASE for recursion
        if (!root) return;
        
        int n = res.size();
        if (n <= level)
        {
            // push, first in the level
            vector<int> t;
            t.push_back(root->val);
            res.push_back(t);
        }
        else
        {
            // Already level entry is present in the result buffer
            res[level].push_back(root->val);
        }
        
        // DO it for both left and right subTrees with level+1
        
        if (root->left) traverse(root->left, level+1, res);
        if (root->right) traverse(root->right, level+1, res);
        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if (!root) return res;
        
        int level = 0;
        traverse(root, level, res);
        
        int i = 1, n = res.size();
        
        while (i < n)
        {
            reverse(res[i].begin(), res[i].end());
            i += 2; // we do reverse only alternate levels
        }
        
        return res;
        
    }
};
