/*
Add Two Numbers II

Solution
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    
    void reverse(ListNode **head)
    {
        if (head == NULL || *head == NULL) return;
        
        ListNode *curr, *prev;
        
        prev = curr = (*head)->next;
        
        // Break chain for last
        (*head)->next = NULL;
        
        while (curr)
        {
            curr = curr->next;
            
            prev->next = *head;
            *head = prev;
            
            prev = curr;
            
        }
        
        // Automatically head points new head
        
    }
    
    void printList(ListNode *head, char *msg)
    {
        if (msg) printf("\n%s : ", msg);
        while (head)
        {
            printf("%d -> ", head->val);
            head = head->next;
        }
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode *res = NULL;
        
        if (l1 == NULL) return res;
        
        /*
        printList(l1, "L1 Original ");
        reverse(&l1);
        printList(l1, "L1 Reversed ");
        
        printList(l2, "L2 Original ");
        reverse(&l2);
        printList(l2, "L2 Reversed ");
        */
        
        reverse(&l1);
        reverse(&l2);
        
        int carry = 0;
        int sum = 0;
        
        //ADD first element out side of the loop
        if (l1)
        {
            sum = l1->val;
            l1 = l1->next;
        }
        
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        if (sum > 9)
            carry = sum / 10;
        
        ListNode *node = new ListNode(sum%10);
        
        res = node;
        ListNode *iter = res;
        
        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            
            carry = (sum > 9) ? sum / 10 : 0;
            
            ListNode *node = new ListNode(sum%10);
            
            iter->next = node;
            iter = iter->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // Do the left over part from one of them if any
        
        while (l1)
        {
            sum = l1->val + carry;
            
            carry = (sum > 9) ? sum / 10 : 0;
            
            ListNode *node = new ListNode(sum%10);
            
            iter->next = node;
            iter = iter->next;
            
            l1 = l1->next;
        }

        
        while (l2)
        {
            sum = l2->val + carry;
            
            carry = (sum > 9) ? sum / 10 : 0;
            
            ListNode *node = new ListNode(sum%10);
            
            iter->next = node;
            iter = iter->next;
            
            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *node = new ListNode(carry);
            iter->next = node;
        }
        
        
        // Now reverse res
        //printList(res, "Result Original ");
        reverse(&res);
        //printList(res, "Result Reversed ");
        return res;
        
        /*
        
        1563 / 1563 test cases passed.
        Status: Accepted
        Runtime: 36 ms
        Memory Usage: 71.5 MB
        Submitted: 0 minutes ago
        */
        
    }
};
