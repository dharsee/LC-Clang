/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
    */
    
    
        
    /*
    Algorithm would be 
        PRE ORDER {root, Left, Right}
        In-Order {Left, Root, Right}
    Pre-order will try to give you the root
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
    
    int findpos2(vector<int>& pre, int pre_start, vector<int>& vect, int l, int h)
    {
        int i, j;
        
        int k = pre.size();
        for (i = pre_start; i < k; i++)
        {
            j = l;    
            while(j < h)
            {
                if (vect[j] == pre[i]) return j;
                j++;
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
    void __buildTree(TreeNode *root, vector<int>& inorder, vector<int>& preorder,
                    int lstart, int lend, int rstart, int rend, int pre_order_start)
    {

        
        if (lstart < lend)
        {
            //devide left child and create link
            int pos = findpos2(preorder, pre_order_start, inorder, lstart, lend);
            TreeNode *curr = getNode(inorder[pos]);
            root->left = curr;
            
            // Do it for recursive
            __buildTree(root->left, inorder, preorder,
                    lstart, pos, pos + 1, lend, pre_order_start + 1);
            
        }
        

        if (rstart < rend)
        {
            //devide Right child and create link
            int pos = findpos2(preorder, pre_order_start, inorder, rstart, rend);
            TreeNode *curr = getNode(inorder[pos]);
            root->right = curr;
            
            // Do it for recursive
            __buildTree(root->right, inorder, preorder,
                    rstart, pos, pos + 1, rend, pre_order_start + 1);
            
            
        }
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n1 = inorder.size();
        int n2 = preorder.size();
        
        if (n1 == 0 || n2 == 0) return NULL;
        
        // create root node
        TreeNode *root = getNode(preorder[0]);
        
        // Find the position in In-Order 
        int pos = findpos(inorder, 0, n1, preorder[0]);
        
        // Last param will help optimizing the TC
        __buildTree(root, inorder, preorder, 0, pos, pos+1, n1, 1);
        
        return root;
    }
    
};
