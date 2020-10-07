/*

Rotate List

Solution
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

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
    
    inline int getLen(ListNode *head, ListNode **last)
    {
        // Find the length of the list, O(N)
        int len = 0;
        
        ListNode *curr = head;
        while (curr && curr->next)
        {
            *last = curr->next;
            len += 2;
            curr = curr->next->next;
            
        }
        
        if (curr) 
        { 
            len++;
            if (curr->next)
                *last = curr->next;
            else
                *last = curr;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
             
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        if (k == 0) return head;
     
        ListNode *curr = NULL;
        ListNode *last = NULL;
        
        int len = getLen(head, &last);    
        
        int kk = k % len; // Rounding towards len of the list;
        
        if (kk == 0) return head;
        
        int i = kk;
        
        // Push kk + 1 elements ahead then start another loop to go to the end       
        ListNode *first_end = head;
        curr = head;
        
        i = kk + 1;
        while (i > 0 && curr)
        {
            curr = curr->next;
            i--;
        }
        
        while (curr)
        {
            curr = curr->next;
            first_end = first_end->next;
        }
        
        
        // Now first_end points last of the first part;
        ListNode *newHead = first_end->next;
        
        first_end->next = NULL; // breaking the chain in two parts
        
        last->next = head;
        head = newHead;
     
        
        return head;
        
    }
    
    
    /*
        231 / 231 test cases passed.
      Status: Accepted
      Runtime: 8 ms
      Memory Usage: 12.1 MB
      Submitted: 0 minutes ago

    
    */
};
