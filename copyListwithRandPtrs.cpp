/*
138. Copy List with Random Pointer
Medium

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {
    
        if (!head) return NULL;
    
        Node *curr = NULL, *prev = NULL;
        
        // These two Data structures are being used to map old random pointers and their index into the new pointers.
        vector<Node *> refs;
        unordered_map<Node *, int> hmap; // NODE -> Index
        
        // Work on head of the node 
        Node *root = new Node(head->val);
        prev = root;
        curr = head->next;
        
        refs.push_back(root);
        hmap[head] =  0;
        
        // Continue to work on rest of the nodes
        int i = 1;
        while (curr)
        {
            //printf("\n Curr - > %d", curr->val);
            Node *temp = new Node(curr->val);
            //temp->random = curr->random;
            refs.push_back(temp);
            hmap[curr] = i;
            
            prev->next = temp;
            
            prev = temp;
            curr = curr->next;
            
            i++;
        }
        
        // walk again from head -  to add their new random pointers from refs list and previous mappings
        
        curr = head;
        Node *c = root;
        while (curr)
        {
            if (curr->random)
            {
                auto iter = hmap.find(curr->random);
                if (iter != hmap.end())
                {
                    c->random = refs[iter->second];
                }
            }
            else
                c->random = NULL;
            
            // Move both old and new list
            c = c->next;
            curr = curr->next;
        }
        
        return root;
    }
};
