/*

147. Insertion Sort List
Medium

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
    
    ListNode * findMin(ListNode *head)
    {
        if (head == NULL) return NULL;
        
        if (head->next == NULL) return head;
        
        ListNode *min = NULL, *curr = NULL, *prev = NULL;
        
        min = prev = head;
        curr = head->next;
        
        ListNode *minParent = NULL;
        
        while (curr)
        {
            if (min->val > curr->val)
            {
                min = curr;
                minParent = prev;
            }
            
            curr = curr->next;
            prev = prev->next;
        }
        
        
        // 
        if (minParent == NULL) // First node is minimum
            //min->next = NULL; // breaking
            ; // dont break chian here; let caller will break it by checking
        else
        {
            minParent->next = min->next;
            min->next = NULL;
        }
        
        return min;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        
        ListNode *dummyNode = new ListNode(-99); // we will not use this for the any other purpose
        ListNode *newHead = NULL;
        
        ListNode *min = findMin(head); // O(N)
        
        if (min == head) // first node itself is the minimum 
        {
            dummyNode->next = min;
            newHead = min->next;
            min->next = NULL;
        }
        else
        {
            // Chain has already broke in the function; lets make this node as root and work on the rest of the nodes
            dummyNode->next = min;
            newHead = head;
        }
        
        
        ListNode *parent = dummyNode->next;
        
        while (newHead)
        {
            min = findMin(newHead);
            
            if (min == newHead) // first node itself is the minimum 
            {
                parent->next = min;
                newHead = min->next;
                min->next = NULL;
            }
            else
            {
                // Chain has already broke in the function; 
                // lets make this node as root and work on the rest of the nodes
                parent->next = min;
                //newHead = head;
            }   
            
            // Move the parent
            parent = parent->next;
        }
        
        
        
        
        return dummyNode->next;
        
    }
    
    
    /*
    
    
    Success
Details 
Runtime: 92 ms, faster than 13.12% of C++ online submissions for Insertion Sort List.
Memory Usage: 9.8 MB, less than 66.91% of C++ online submissions for Insertion Sort List.

*/
};
