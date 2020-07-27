/*

Construct Binary Tree from Inorder and Postorder Traversal

Solution
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    
    /*
    Algorithm would be 
        POST ORDER {Left, Right, Root}
        In-Order {Left, Root, Right}
    Post-order will try to give you the root
    In-order will find its left children list and right children list
    Do this recursively
     */  
    
    
    int findpos(vector<int>& vect, int l, int h, int val)
    {
        while(l < h)
        {
            if (vect[l] == val) return l;
            l++;
        }
        return l;
    }
    
    int rfindpos(vector<int>& post, int post_sz, vector<int>& vect, int l, int h)
    {
        int i, j;
        
        
        for (i = post_sz - 1; i >= 0; i--)
        {
            j = h - 1;    
            while(j >= l)
            {
                if (vect[j] == post[i]) return j;
                j--;
            }
        }
        
        // Should not come here;
        return l;
    }
    
    TreeNode * getNode(int val)
    {
        TreeNode *root = new TreeNode;
        root->val = val;
        root->left = root->right = NULL;
        
        return root;
    }
    
    // Last param will help optimizing the TC
    void __buildTree(TreeNode *root, vector<int>& inorder, vector<int>& postorder,
                    int lstart, int lend, int rstart, int rend, int post_order_size)
    {
        // Build right child first to optimize search space for the root.
        if (rstart < rend)
        {
            //devide Right child and create link
            int pos = rfindpos(postorder, post_order_size, inorder, rstart, rend);
            TreeNode *curr = getNode(inorder[pos]);
            root->right = curr;
            
            // Do it for recursive
            __buildTree(root->right, inorder, postorder,
                    rstart, pos, pos + 1, rend, post_order_size - 1);
            
            
        }
        
        if (lstart < lend)
        {
            //devide left child and create link
            int pos = rfindpos(postorder, post_order_size, inorder, lstart, lend);
            TreeNode *curr = getNode(inorder[pos]);
            root->left = curr;
            
            // Do it for recursive
            __buildTree(root->left, inorder, postorder,
                    lstart, pos, pos + 1, lend, post_order_size - 1);
            
        }
        
        
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n1 = inorder.size();
        int n2 = postorder.size();
        
        if (n1 == 0 || n2 == 0) return NULL;
        
        // create root node
        TreeNode *root = getNode(postorder[n2-1]);
        
        // Find the position in In-Order 
        int pos = findpos(inorder, 0, n1, postorder[n2-1]);
        
        // Last param will help optimizing the TC
        __buildTree(root, inorder, postorder, 0, pos, pos+1, n1, n2 - 1);
        
        return root;
    }
};
