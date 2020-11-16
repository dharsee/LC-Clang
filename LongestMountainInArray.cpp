/*
Longest Mountain in Array

Solution
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.
Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000
Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?

*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        int n = A.size();
        if (n <= 2) return 0;
        
        int left_index = 0, right_index = 0;
        int curr_len = 0, max_len = 0;
        
        int i, j, k, l;
        
        //Scan vector from left to right
        
        for (i = 1; i < n - 1; i++)
        {
            if (A[i] > A[i-1] && A[i] > A[i+1])
            {
                left_index = i - 1;
                
                // Move left side as long as you can
                
                while (left_index > 0 && A[left_index] > A[left_index - 1])
                    left_index--;
                
                // Do the same for right index
                
                right_index = i + 1;
                
                while (right_index < n - 1 && A[right_index] > A[right_index + 1])
                    right_index++;
                
                max_len = max(max_len, right_index - left_index + 1);
            }
        }

        return max_len;
    }
    
    /*
    72 / 72 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 18.8 MB
Submitted: 10 minutes ago

    
    */
    
};
