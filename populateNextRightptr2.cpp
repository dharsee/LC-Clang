/*
117. Populating Next Right Pointers in Each Node II
Medium

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/


// This solution would take O(N) space
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    // This will Take O(N) space
    void traverse(Node *root, vector<vector<Node*>> &res, int level)
    {
        if (!root) return;
        
        int n = res.size();
        if (n < level + 1)
        {
            vector<Node*> r;
            r.push_back(root);
            res.push_back(r);
        }
        else
            res[level].push_back(root);
        
        //do the same for left and right sub trees
        
        traverse(root->left, res, level+1);
        traverse(root->right, res, level+1);
        
    }
    
    Node* connect(Node* root) {

        if(!root) return NULL;
        
        if (root->left == NULL && root->right == NULL)
            return root;
  
        //Lets build level order node and then add the links from left to right with in the level
        
        vector<vector<Node*>> res;
        
        traverse(root, res, 0);
        
        // Create links
        
        int n = res.size();
        int i = 0;
        
        while (i < n)
        {
            int k = 1;
            int m = res[i].size();
            
            while (k < m)
            {
                res[i][k-1]->next = res[i][k];
                k++;
            }
            i++;
        }
        
        return root;
    }
};
