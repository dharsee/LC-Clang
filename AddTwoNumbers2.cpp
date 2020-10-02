/*
445. Add Two Numbers II
Medium

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Maintain 3 stacks, each for L1, L2 and for result
        
        stack<int> st1, st2, res_st;
        
        // Push input LIST on to stacks
        
        ListNode * c1 = l1, *c2 = l2;
        while (c1 && c2)
        {
            st1.push(c1->val);
            st2.push(c2->val);
            
            c1 = c1->next;
            c2 = c2->next;
        }
        
        // Left over items if any
        while (c1)
        {
            st1.push(c1->val);
            c1 = c1->next;
        }
        while (c2)
        {
            st2.push(c2->val);
            c2 = c2->next;
        }
        
        
        // Now pop elements from each stack and push into 3rd stack(res)
        int carry = 0;
        while (!st1.empty() && !st2.empty())
        {
            int sum = carry + st1.top() + st2.top();
            st1.pop(); st2.pop();
            int curr = sum % 10;
            carry = sum / 10;
            
            res_st.push(curr);
        }
        
        // Do it for left-over if any 
        while (!st1.empty())
        {
            int sum = carry + st1.top();
            st1.pop();
            int curr = sum % 10;
            carry = sum / 10;
            
            res_st.push(curr);
        }
        
        while (!st2.empty())
        {
            int sum = carry + st2.top();
            st2.pop();
            int curr = sum % 10;
            carry = sum / 10;
            
            res_st.push(curr);
        }
        
        if (carry) res_st.push(carry);
        
        
        
        
        // NOW BUILD the result Linked LIST by reading st
        ListNode *res = NULL;
        ListNode *curr = NULL, *temp = NULL;
        
        while (!res_st.empty())
        {
            temp = new ListNode(res_st.top());
            res_st.pop();
            temp->next = NULL;
            
            if (res == NULL)
            {
                curr = res = temp;
            }   
            else
            {
                curr->next = temp;
                curr = temp;
            }
        }
        
        return res;
        
        /*
            Solution is good and straight but consuming more memory for the temporary stacks
            
            Details 
            Runtime: 36 ms, faster than 74.74% of C++ online submissions for Add Two Numbers II.
            Memory Usage: 75 MB, less than 5.05% of C++ online submissions for Add Two Numbers II.
        */
        
    }
};
