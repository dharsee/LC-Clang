/*
 Minimum Depth of Binary Tree

Solution
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

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
    
    void depth(TreeNode *root, int level, int &min_so_far)
    {
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL)
        {
            if (min_so_far > level) min_so_far = level;
        }
        
        // Do it for left and right sub trees
        if (root->left) depth(root->left, level + 1, min_so_far);
        if (root->right) depth(root->right, level + 1, min_so_far);
    }
    
    int minDepth(TreeNode* root) {
        
        int level = 1;
        int min_so_far = INT_MAX;
        
        if (root == NULL) return 0;
        //if (root->left == NULL || root->right == NULL) return 1;
        
        depth(root, level, min_so_far);
        
        return min_so_far;
            
    }
    
    /*
    
    52 / 52 test cases passed.
Status: Accepted
Runtime: 328 ms
Memory Usage: 144.4 MB
Submitted: 0 minutes ago

    */
};
