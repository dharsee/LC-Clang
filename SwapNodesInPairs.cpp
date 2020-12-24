
/*
Swap Nodes in Pairs

Solution
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes. Only nodes itself may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (head == NULL || head->next == NULL) return head;
        
        //create a dummy node 
        
        ListNode *A = new ListNode(-9, NULL);
        
        A->next = head;
        
        ListNode *prev = NULL, *B = NULL, *C = NULL, *D = NULL;
        
        head = NULL;
        
        while (A->next && A->next->next) {
            prev = A;
            B = A->next;
            C = B->next;
            D = C->next;
            
            prev->next = C;
            C->next = B;
            B->next = D;
            if (head == NULL) head = prev->next;
            
            A = B;
        }

        return head;

        /*
        
        55 / 55 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 8 MB
Submitted: 0 minutes ago

        */
    }
};
