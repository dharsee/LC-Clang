/*
572. Subtree of Another Tree
Easy

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.



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
    
    bool traverse(TreeNode *s, TreeNode *t)
    {
        if (!s && !t) return true;
        if ((s && !t) || (!s && t)) return false;
        
        if (s->val != t->val) return false;
        
        // Do it for left subtree and right subtree
        
        bool l = traverse(s->left, t->left);
        if (l == false) return false;
        
        bool r = traverse(s->right, t->right);
        return r;
    }
    
    bool check(TreeNode *s, TreeNode *t)
    {
        if (!s && !t) return true;
        if ((s && !t) || (!s && t)) return false;
        
        if (s->val == t->val)
        {
            
            bool ret = traverse(s, t);
            //printf("\n s : %d t : %d, ret = %d ", s->val, t->val, ret);
            if (ret == true) return true;
            
            // Try with other option if this chioce failed
        }
        
        bool l = check(s->left, t);
        if (l == true) return true;
        
        bool r = check(s->right, t);
        return r;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        return check(s, t);
        
    }
};
