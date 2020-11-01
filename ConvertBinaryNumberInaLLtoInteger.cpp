/*
Convert Binary Number in a Linked List to Integer

Solution
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.


Hide Hint #1  
Traverse the linked list and store all values in a string or array. convert the values obtained to decimal value.

Hide Hint #2   <----- This is very good idea to optimize sapce  
You can solve the problem in O(1) memory using bits operation. use shift left operation ( << ) and or operation ( | ) to get the decimal value in one operation.

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
    
    // Without using EXTRA STorage 
    // Cleanest way to solve this problem
    int getDecimalValue(ListNode* head) {
        
        if (head == NULL) return 0;
        
        if (head->next == NULL) return head->val;
        
        ListNode *curr = head;
        int res = 0;
        
        while(curr)
        {
            res = (res << 1) | curr->val;
            curr = curr->next;
        }
        

        /*
            102 / 102 test cases passed.
            Status: Accepted
            Runtime: 0 ms
            Memory Usage: 8.5 MB
            Submitted: 0 minutes ago

        */
        
        return res;
    }
    
#if 0
    
    // Using extra stack/array which SPACE O(N)
    int getDecimalValue(ListNode* head) {
        
        // Maintain stack to hold bin values
        stack<bool> st;
        if (head == NULL) return 0;
        
        if (head->next == NULL) return head->val;
        
        ListNode *curr = head;
        
        while(curr)
        {
            st.push(curr->val);
            curr = curr->next;
        }
        
        // Now pop each element and compute the decimal integer
        int res = 0;
        int i = 0;
        
        while (!st.empty())
        {
            int curr = st.top();
            if (curr == 1)
            {
                //res = res + pow(2, i);
                res = res + (1 << i); // Optimization over power ()
            }
            
            st.pop();
            i++;
        }
        
        /*
                    102 / 102 test cases passed.
            Status: Accepted
            Runtime: 0 ms
            Memory Usage: 8.7 MB
            Submitted: 0 minutes ago

        */
        
        return res;
    }
#endif
};
