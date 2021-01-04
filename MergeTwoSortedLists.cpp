/*
Merge Two Sorted Lists

Solution
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *res = NULL, *curr = NULL;
        if (l1 == NULL && l2) return l2;
        else if (l1 && l2 == NULL) return l1;
        else if (l1 == NULL && l2 == NULL) return res;
        
        if (l1->val < l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        
        curr = res;
        while (l1 && l2)
        {
            while (l1 && l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            
            while (l1 && l2 && l1->val > l2->val)    
            {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        
        // Left over from either of the list
        
        if (l1)
        {
          curr->next = l1;  
        }
        else if (l2)
        {
            curr->next = l2;
        }
        
        return res;
    }
};
