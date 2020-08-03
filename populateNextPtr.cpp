/*
116. Populating Next Right Pointers in Each Node
Medium

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
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 
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
    
    
    // Recursive Solution
    void __connect(Node *left, Node *right)
    {
        if (!left && !right) return;
        
        if (!left || !right) return;
        
        left->right = right;
        
        __connect(left->left, left->right);
        __connect(right->left, right->right);
    }
    
    Node* connect(Node* root) {

        if(!root) return NULL;
        
        if (root->left == NULL && root->right == NULL)
            return root;

        #if 0
        /*
        //Recursive solution which will use system stack which cannot count as SP complexity
        // Not working at this point in time
        __connect(root->left, root->right);
    
        return root;
        */
        #endif
        
        /* Using extra space, queue for BFS algorithm */
        queue<Node *> q;
        
        q.push(root);
    
        Node *curr = NULL, *prev = NULL;
        
        int i = 1;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            
            // add its children
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            
            if (i > 2 && (i & (i-1)) == 0)
            {
                prev = NULL;
            }
            else
            {
                if (i > 2 && prev)
                {
                    prev->next = curr;
                }
            }
        
            prev = curr;
            i++;
        } // End of while loop
        
        return root;
        
    }
};
