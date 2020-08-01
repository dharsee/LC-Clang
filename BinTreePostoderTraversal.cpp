/*
Binary Tree Postorder Traversal

Solution
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
class Solution {
public:
    
    void traverse(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        
        traverse(root->left, res);
        traverse(root->right, res);
        res.push_back(root->val);
        
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if (!root) return res;
    
        /* 
        // Recursive method
        traverse(root, res);
        return res;
        */
        
        // Iterative method for Post Order Binary tree traversal
        // 2 Stack method
        
        stack<TreeNode *> st;
        //stack<int> st_res;
        
        TreeNode *curr = root;
        
        // add root of the tree to the stack
        st.push(root);
        
        
        while (!st.empty())
        {
            // Pop one element from stack and add its value to result stack
            curr = st.top();
            st.pop();
            
            //st_res.push(curr->val);
            res.push_back(curr->val);
            
            
            // Now add it two children to the stack
            
            if (curr->left) st.push(curr->left);
            if (curr->right) st.push(curr->right);
            
            
        } //End of while loop
        
        
        // Add result to the vector by popping each element from stack
        /*
        while (!st_res.empty())
        {
            res.push_back(st_res.top());
            st_res.pop();
        }
        */
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
