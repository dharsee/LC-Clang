/*
Sort List

Solution
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105


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

/// APPLY merge sort 
// divide list in two halves recursively until it becomes single node which is self sorted
// merge two sorted list and return back

ListNode *merge(ListNode *l1, ListNode* l2)
{
    // Maintain dummy node; may wasting memory for reduce complexity of the code
    ListNode *dummyNode = new ListNode(-99); // WE dont use this val as node ay any time
    
    ListNode *curr = dummyNode;
    
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        
        curr = curr->next;
    }
    
    // Append left over if any
    
    curr->next = l1 ? l1 : l2;
    
    return dummyNode->next; // Here we are ignoring the dummynode that is created in the beginning
}


ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head, *fast = head->next;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *mid = slow->next;
    
    // Break the chain
    slow->next = NULL;
    
    return mid;
}


ListNode *mergeSort(ListNode *head)
{
    if (head == NULL || head->next == NULL) return head;
    
    ListNode *mid = findMiddle(head); // This function will return middle of the list
    
    // call recusrive on left sublist and right sublist
    
    ListNode *left = mergeSort(head); // Hoping that findMiddle will break the chain
    ListNode *right = mergeSort(mid);
    
    // Merge two Sorted Lists
    
    return merge(left, right);
}


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        
        return mergeSort(head);
        
    }
    
    /*
                16 / 16 test cases passed.
            Status: Accepted
            Runtime: 60 ms
            Memory Usage: 30.6 MB
            Submitted: 0 minutes ago
    
    */
};
