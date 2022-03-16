/*
946. Validate Stack Sequences
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of 
push and pop operations on an initially empty stack, or false otherwise.

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int i, n = pushed.size();
        
        i = 0;
        int j = 0;
        while (i < n) {
            if (pushed[i] == popped[j])
            {
                i++;
                j++;
                
                
                while (!st.empty() && j < n) {
                    //cout << endl << "Top = " << st.top() << " Pop = " << popped[j];
                    if (st.top() != popped[j])
                        //return false;
                        break;
                    st.pop();
                    j++;
                }
                    
                continue;
            }
            
            //let push this item on the stack
            st.push(pushed[i]);
            i++;
        }
        
        //cout << endl << " Out of insertion, j = " << j;
        
        while (!st.empty() && j < n) {
            //cout << endl << "Top = " << st.top() << " Pop = " << popped[j];
            if (st.top() != popped[j])
                return false;
            st.pop();
            j++;
        }
        
        
        //cout << endl << "before return j = " << j << " n = " << n << " Empty = " << st.empty();
        
        return st.empty() && j == n;
        
    }
};


/*

Success
Details 
Runtime: 8 ms, faster than 83.81% of C++ online submissions for Validate Stack Sequences.
Memory Usage: 15.5 MB, less than 15.68% of C++ online submissions for Validate Stack Sequences.

*/
