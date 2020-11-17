/*

Populating Next Right Pointers in Each Node

Solution
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

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



Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to 
its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

*/

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
    /*
    Maintain a queue to keep nodes in the level order, also maintain a nth node
    last node of the level should be at pow(2)
     */  
    Node* connect(Node* root) {
     
        if (root == NULL) return root;
        if (root->left == NULL &&  root->right == NULL) return root;
        
        queue<Node *> q;
        
        // First load root of the tree in queue manually
        
        q.push(root);
        
        Node *curr = NULL;
        Node *prev = NULL;
        
        //maintain i to know the ith node, for a full binary tree, pow(2, i) should be last of the that level
        int i = 1;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            
            // Optimized
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            
            if (i > 2)
            {
                // is this node last of the level , check by ith in sequence 
                if ((i & (i - 1)) == 0) // End of the level
                    prev = NULL;
                else if (prev) prev->next = curr; 
            }
            
            prev = curr;
            i++;
        } // End of while loop
        
        /*
        
                58 / 58 test cases passed.
        Status: Accepted
        Runtime: 24 ms
        Memory Usage: 17.6 MB
        Submitted: 0 minutes ago

        */
        
        return root;
    }
};
