/*
Sum of Square Numbers

Solution
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
Example 3:

Input: c = 4
Output: true
Example 4:

Input: c = 2
Output: true
Example 5:

Input: c = 1
Output: true
 

Constraints:

0 <= c <= 231 - 1

*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long int hi = sqrt(c), lo = 0;
        
        while (lo <= hi) {
            long long int curr = lo * lo + hi * hi;
            if (curr == c) return true;
            else if(curr < c) lo++;
            else hi--;
        }
        
        return false;
        
    }
};

/*

124 / 124 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 5.9 MB


*/
