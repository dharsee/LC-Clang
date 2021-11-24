/*
Reverse Linked List

Solution
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    
    // Recursive method,
    // we need prev node details to make the reverse links
    
    ListNode * _rev(ListNode *prev, ListNode *curr) {
        
        if (curr == NULL) { /* Last node in the orig list */
            return prev;
        }
        
        if (prev == NULL) { /* first node in the orig list */
            prev = curr;
            ListNode * temp = curr->next;
            curr->next = NULL;
            
            return _rev(prev, temp);
        }
        
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        
        return _rev(prev, curr);
        
    }
    
    ListNode* reverseList(ListNode* head) {
        return _rev(NULL, head);
    }
    
    /*
    Iterattive method
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode *curr = NULL, *prev = NULL, *next = NULL;
        
        if (head == NULL || head->next == NULL) return head;
        
        curr = head;
        prev = head;
        
        
        
        curr = curr->next;
        
        prev->next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            
            curr = next;
            
        }
        
        return prev;
    }
    */
    
};

