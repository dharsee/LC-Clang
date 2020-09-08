/*
1080. Insufficient Nodes in Root to Leaf Paths
Medium

Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.  (A leaf is a node with no children.)

A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.

Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

 

Example 1:


Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1

Output: [1,2,3,4,null,null,7,8,9,null,14]
Example 2:


Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22

Output: [5,4,8,11,null,17,4,7,null,null,null,5]
 

Example 3:


Input: root = [1,2,-3,-5,null,4,null], limit = -1

Output: [1,null,-3,4]
 

Note:

The given tree will have between 1 and 5000 nodes.
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9


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
    
    bool traverse(TreeNode *root, int limit, int sum)
    {
     
        // Base case
        if (!root) return true;
        
        // Check path sum for leaf node
        if (root->left == NULL && root->right == NULL)
        {
            //printf("\n Leaf node: %d and Sum  = %d limit = %d ", root->val, sum+root->val, limit);
            if (sum + root->val >= limit) return true;
            else return false;
        }
        
        
        // Do the same for left and right sub-trees
        bool l = false, r = false;
        
        l = traverse(root->left, limit, sum + root->val);
        r = traverse(root->right, limit, sum + root->val);
        
        
        // Post processing, this is very important
        
        //printf("\n Node : %d  Sum = %d l = %d r = %d ", root->val, sum + root->val, l, r);
        
        if (l == true && r == true) return true;
        else if (l == false && r == false)
        {
            root->left = NULL;
            root->right = NULL;
            return false;
        }
        else if (l == false)
        {
            root->left = NULL;
            if (root->right) return r;
            else return false;
        }
        else
        {
            root->right = NULL;
            if (root->left) return l;
            else return false;
        }
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        int sum = 0;
        
        bool l = traverse(root, limit, sum);
        
        // This is to handle whole tree is insufficient
        if (l == false) return NULL;
        return root;
    }
};
