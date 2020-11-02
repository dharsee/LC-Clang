/*

Insertion Sort List

Solution
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

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
    
    // Expecting input node has already got separated from the chain
    // also head has end null terminated
    inline void __insert(ListNode** head, ListNode **last, ListNode *input)
    {
        if (head == NULL || *head == NULL || input == NULL || last == NULL || *last == NULL) return;
        
        if (input->val < (*head)->val) // Insert at beginning
        {
            input->next = *head;
            *head = input;
        }
        else 
        {
            // Great Optimization      
            // Just check if this element belongs to last of the list then append 
            if ((*last)->val < input->val)
            {
                (*last)->next = input;
                *last = input;
                return;
            }
            
            
            // Traverse according to position
            bool added = false;
            ListNode *curr = *head;
            while (curr && curr->next)
            {
                if (input->val < curr->next->val)
                {
                    input->next = curr->next;
                    curr->next = input;
                    added = true;
                    break;
                }
                else
                {
                    curr = curr->next;
                }
            }
            
            if(!added)
            {
                curr->next = input;
                *last = input;
            }
        }
        
    }
    
    ListNode* insertionSortList(ListNode* head) {
        
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *curr = NULL;
        
        curr = head->next;
        
        // break the chain
        head->next = NULL;
        
        ListNode *last = head;
        
        while (curr)
        {
            ListNode *next = curr->next;
            
            curr->next = NULL;
            
            __insert(&head, &last, curr);
            
            curr = next;
        }
      
    /*
        Tracking of tail pointer is helping a lot in the runtime 
            22 / 22 test cases passed.
            Status: Accepted
            Runtime: 16 ms
            Memory Usage: 9.9 MB
            Submitted: 0 minutes ago

        Without tracking tail pointer
                22 / 22 test cases passed.
            Status: Accepted
            Runtime: 52 ms
            Memory Usage: 10.1 MB
            Submitted: 0 minutes ago
    */
        
        return head;
    }
};
