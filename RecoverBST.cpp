/*
Recover Binary Search Tree

Solution
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1


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
    TreeNode *firstStartPoint, *lastEndPoint, *prev;
public:
    
    /*
     WE can take advantage of In-Order traversal of BST which would give us 
     Sorted order of keys/values
     
     There might be one or two pair(s) of indices would be in wrong order, like
     a[i] > a[i+1] --> is wrong order wrt Ascending order (In-order Traversal)
    
     There will be 2 cases - 
          #1. Having two separate pair <p1.1, p1.2> and <p2.1, p2.2>
              --> if this is the case then swap p1.1 with p2.2 to make it into order
          #2. Having single pair adjucent to each other <p1, p2>
                --> In this case swap two values to make it in-order
    */
    
    //void inOrder(TreeNode *root, TreeNode **firstStartPoint, TreeNode **lastEndPoint, TreeNode **prev)
    void inOrder(TreeNode *root)
    {
        if (root == NULL) return;
        
        inOrder(root->left);
        
        // Data; Root node
        
        if (prev && prev->val > root->val) // This indicates voilating order
        {
            // Now check firstStartPoint is already seen or not
            if (firstStartPoint == NULL) firstStartPoint = prev;
            
            // Keep tracking last End point always whenever we see dis-order
            lastEndPoint = root;
        }
        
        prev = root; // Keep this node as prev, since it is now visisted
        
        inOrder(root->right);
    
    }
    
    void recoverTree(TreeNode* root) {
    
        // Initialize Global variables
        firstStartPoint = NULL;
        lastEndPoint = NULL;
        prev = NULL;
        
        inOrder(root);
        
        /*
        printf("\n First : %d Last : %d ", firstStartPoint ? firstStartPoint->val : -909,
              lastEndPoint ? lastEndPoint->val : -909);
        */
        // These two are pointing to first of first/only pair and last of last/only pair.
        // Now swap
        
        int t = firstStartPoint->val;
        firstStartPoint->val = lastEndPoint->val;
        lastEndPoint->val = t;
        
        
        /*
        
        // This method is better than previous solution
                    1918 / 1918 test cases passed.
            Status: Accepted
            Runtime: 32 ms
            Memory Usage: 58.2 MB
            Submitted: 0 minutes ago

        */
        
    }
    
#if 0
    // This solution is passing 3 arguments to inorder to track pairs and calling swap function
    void inOrder(TreeNode *root, TreeNode **firstStartPoint, TreeNode **lastEndPoint, TreeNode **prev)
    {
        if (root == NULL) return;
        
        inOrder(root->left, firstStartPoint, lastEndPoint, prev);
        
        // Data; Root node
        
        if (*prev && (*prev)->val > root->val) // This indicates voilating order
        {
            // Now check firstStartPoint is already seen or not
            if (*firstStartPoint == NULL) *firstStartPoint = *prev;
            
            // Keep tracking last End point always when ever we see did-order
            *lastEndPoint = root;
        }
        
        *prev = root; // Keep this node as prev, since it is now visisted
        
        inOrder(root->right, firstStartPoint, lastEndPoint, prev);
    
    }
    
    // Swap helper function
    inline void swap(TreeNode *N1, TreeNode *N2)
    {
        int t = N1->val;
        N1->val = N2->val;
        N2->val = t;
    }
    
    void recoverTree(TreeNode* root) {
    
        TreeNode *firstStartPoint = NULL, *lastEndPoint = NULL, *prev = NULL;
        
        inOrder(root, &firstStartPoint, &lastEndPoint, &prev);
        
        /*
        printf("\n First : %d Last : %d ", firstStartPoint ? firstStartPoint->val : -909,
              lastEndPoint ? lastEndPoint->val : -909);
        */
        // These two are pointing to first of first/only pair and last of last/only pair.
        // Now swap
        
        swap(firstStartPoint, lastEndPoint);
        
        
        /*
        
                1918 / 1918 test cases passed.
        Status: Accepted
        Runtime: 60 ms
        Memory Usage: 58.3 MB
        Submitted: 0 minutes ago
        */
        
    }
#endif
};
