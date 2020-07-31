/*
Binary Tree Inorder Traversal

Solution
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    void traverse(TreeNode *root, vector<int> &res)
    {
        // BASE case for recursion
        if (!root) return;
        
        // First visit Left sub tree
        traverse(root->left, res);
        
        // Visit root node 
        // Since this is just to add val to the result so 
        res.push_back(root->val);
        
        // Finally visit Right sub-tree
        traverse(root->right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if (!root) return res;
        
        /* 
        // Recursive method 
        
        traverse(root, res);
        return res;
        */
        
        /* Lets Focus on the iteravie method. */
        
        TreeNode *curr = root;
        stack<TreeNode *> st;
        
        while (curr)
        {
            //printf(" %d \n", curr->val);
            
            if (curr->left)
            {
                st.push(curr);
                curr = curr->left;
                continue;
            }
            else
            {
                // process root, since there is no left for this 
                res.push_back(curr->val);
                
                // move to right of the tree
                curr = curr->right;
                
                if (curr == NULL)
                {
                    // here is when you are kind of going back, now see if there are any nodes left over 
                    // Keeping two conditions are mandetory
                    
                    while (!st.empty() && !curr)
                    {
                        curr = st.top();
                        st.pop();
                        
                        // process root, since there is no left for this 
                        res.push_back(curr->val); // This is to avoid loop
                        
                        curr = curr->right;
                    }
                }
            }
        } // End of while loop
        
        return res;
        
    }
};
