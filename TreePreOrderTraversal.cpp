/*
Binary Tree Preorder Traversal

Solution
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?

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
 
 
 // This has code for recursive and iterative method of pre-order traversal.
 
class Solution {
public:
    void traverse(TreeNode *root, vector<int> &res)
    {
        if (!root) return;
        
        // Visit root first
        res.push_back(root->val);
        
        // Visit left sub-Tree
        traverse(root->left, res);
        
        // Visiti right sub-tree
        traverse(root->right, res);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        /* Recursive method 
        vector<int> res;
        
        traverse(root, res);
        
        return res;
        */
        
        
        // Lets focus on the iterative method - pre-order tarversal
        
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode *> st;
        
        st.push(root);
        
        
        while(!st.empty())
        {
            // pop front element of the queue
            TreeNode *curr = st.top();
            st.pop(); // Detele front element
            
            // First visit root
            res.push_back(curr->val);
            
            /*
            Since this is iterative method and using stack, push right first to process it later
            then push left so that we can process left first.
            */
            
            //Insert its right
            if (curr->right) st.push(curr->right);
            
            // Insert its left 
            if (curr->left) st.push(curr->left);
            
        }
        
        return res;
    }
};
