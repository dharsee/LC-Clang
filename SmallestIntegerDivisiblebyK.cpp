/*
1015. Smallest Integer Divisible by K

Given a positive integer K, you need to find the length of the smallest positive integer N 
such that N is divisible by K, and N only contains the digit 1.

Return the length of N. If there is no such N, return -1.

Note: N may not fit in a 64-bit signed integer.

 

Example 1:

Input: K = 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.
Example 2:

Input: K = 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.
Example 3:

Input: K = 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3.
 

Constraints:

1 <= K <= 105


*/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        
        int rem = 0;
        int len = 0;
        
        
        for (len = 1; len <= K; len++)
        {
            rem = (rem * 10 + 1) % K;
            if (rem == 0) return len;
        }
        
        return -1;
    }
    
    /*

            Success
        Details 
        Runtime: 4 ms, faster than 57.58% of C++ online submissions for Smallest Integer Divisible by K.
        Memory Usage: 6.1 MB, less than 96.97% of C++ online submissions for Smallest Integer Divisible by K.
    
    */
};
