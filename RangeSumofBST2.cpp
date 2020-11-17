/*

Range Sum of BST

Solution
Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.

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
    
    /* This method will explor entire tree and sum node val only if they are eligible */
    
    void traverse_full(TreeNode* root, int low, int high, int &sum)
    {
        if (root == NULL) return;
        
        if (root->val >= low && root->val <= high)
            sum += root->val;
        
        traverse_full(root->left, low, high, sum);
        traverse_full(root->right, low, high, sum);
        
        /*
                    41 / 41 test cases passed.
            Status: Accepted
            Runtime: 188 ms
            Memory Usage: 65.2 MB
            Submitted: 0 minutes ago
        
        */
        
    }
    
    
    /* This method will explor entire tree and sum node val only if they are eligible */
    
    void traverse(TreeNode* root, int low, int high, int &sum)
    {
        if (root == NULL) return;
    
        
        if (root->val >= low && root->val <= high)
            sum += root->val;
    

        // Optimization
        if (low  <= root->val) traverse(root->left,  low, high, sum);
        if (high >= root->val) traverse(root->right, low, high, sum);
        
        /*
                41 / 41 test cases passed.
        Status: Accepted
        Runtime: 160 ms
        Memory Usage: 65.2 MB
        Submitted: 0 minutes ago

      
        */
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int res = 0;
        
        //traverse_full(root, low, high, res);
        traverse(root, low, high, res);
        
        return res;
    }
};
