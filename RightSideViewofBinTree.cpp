/*
199. Binary Tree Right Side View
Medium

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


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
    
    // In this solution we want to travese the tree in the level order and add the last node in the level
    // to the result and keep traversing
    void levelOrderTraverse(TreeNode *root, vector<int> &res)
    {
        if (!root) return;
        
        //maintaine a queue with "NULL" indicates end of the level
        int last = 0;
        
        queue<TreeNode *> q;
        
        //start with root;
        q.push(root);
        q.push(NULL);

        TreeNode *curr = NULL;
        
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            
            
            if (curr == NULL)
            {
                res.push_back(last);
                
                if (q.empty()) break; // This is to avoid loop
                
                q.push(NULL); // In the last iterate we must have added all children, so dd NULL for delimiter
                
                continue;
            }
            
            //printf("\n Q item : %d ", curr? curr->val : -999);
            
            // Add its children back to q, since we removed root node
            //if (curr && curr->left) q.push(curr->left);
            //if (curr && curr->right) q.push(curr->right);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            
            
            
            last = curr ? curr->val : -999;
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        
        if (!root) return res;
        
        levelOrderTraverse(root, res);
        
        return res;
    }
    
    
    #if 0
    /* This code will not work when you have deeper left sub tree
       Solution would be, find last node in the level order traversal
     */
    void traverse(TreeNode *root, vector<int> &res)
    {
        if (!root) return;
        
        res.push_back(root->val);
        
        if (root->right) traverse(root->right, res);
        else if (root->left) traverse(root->left, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        
        traverse(root, res);
        
        return res;
        
    }
    #endif
    
};
