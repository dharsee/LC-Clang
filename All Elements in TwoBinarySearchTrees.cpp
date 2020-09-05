/*
All Elements in Two Binary Search Trees

Solution
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
   Hide Hint #1  
Traverse the first tree in list1 and the second tree in list2.
   Hide Hint #2  
Merge the two trees in one list and sort it.

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
    
    void inorder_traverse(TreeNode *root, vector<int> &res)
    {
        if (!root) return;
        
        inorder_traverse(root->left, res);
        
        res.push_back(root->val);
        inorder_traverse(root->right, res);
    
        
    }
    
    void print_v(vector<int> &A)
    {
        int i, n = A.size();
        
        printf("\n");
        for (i = 0; i < n; i++)
            printf(" %3d ", A[i]);
    }
    
    void merge(vector<int> &r1, vector<int> &r2, vector<int> &r3)
    {
        int i, j, n1 = r1.size(), n2 = r2.size();
        
        i = 0, j = 0;
        int k = 0;
        while(i < n1 && j < n2)
        {
            if (r1[i] <= r2[j])
            {
                r3[k] = r1[i];
                i++;
            }
            else
            {
                r3[k] = r2[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) r3[k++] = r1[i++];
        
        while (j < n2) r3[k++] = r2[j++];
        
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> r1, r2;
        
        inorder_traverse(root1, r1);
        //print_v(r1);
        
        inorder_traverse(root2, r2);
        //print_v(r2);
        
        
        vector<int> res(r1.size() + r2.size(), 0);
        merge(r1, r2, res);
        
        return res;
    }
    
    
    
};
