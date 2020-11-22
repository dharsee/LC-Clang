/*
902. Numbers At Most N Given Digit Set
Hard

Given an array of digits, you can write numbers using each digits[i] as many times as we want.  
For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

Example 1:

Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
Example 3:

Input: digits = ["7"], n = 8
Output: 1
 

Constraints:

1 <= digits.length <= 9
digits[i].length == 1
digits[i] is a digit from '1' to '9'.
All the values in digits are unique.
1 <= n <= 109



// Solution Section

Approach 1: Dynamic Programming + Counting
Intuition

First, call a positive integer X valid if X <= N and X only consists of digits from D. Our goal is to find the number of valid integers.

Say N has K digits. If we write a valid number with k digits (k < K), then there are (D\text{.length})^k(D.length) 
k
  possible numbers we could write, since all of them will definitely be less than N.

Now, say we are to write a valid K digit number from left to right. For example, N = 2345, K = 4, and D = '1', '2', ..., '9'. Let's consider what happens when we write the first digit.

If the first digit we write is less than the first digit of N, then we could write any numbers after, for a total of (D\text{.length})^{K-1}(D.length) 
K−1
  valid numbers from this one-digit prefix. In our example, if we start with 1, we could write any of the numbers 1111 to 1999 from this prefix.

If the first digit we write is the same, then we require that the next digit we write is equal to or lower than the next digit in N. In our example (with N = 2345), if we start with 2, the next digit we write must be 3 or less.

We can't write a larger digit, because if we started with eg. 3, then even a number of 3000 is definitely larger than N.

Algorithm

Let dp[i] be the number of ways to write a valid number if N became N[i], N[i+1], .... For example, if N = 2345, then dp[0] would be the number of valid numbers at most 2345, dp[1] would be the ones at most 345, dp[2] would be the ones at most 45, and dp[3] would be the ones at most 5.

Then, by our reasoning above, dp[i] = (number of d in D with d < S[i]) * ((D.length) ** (K-i-1)), plus dp[i+1] if S[i] is in D.





*/


/* Copied from the solution */
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string s = to_string(n);
        int K = s.length(); // Will know number of digits that n contains.
        
        vector<int> dp(K+1, 0);
        
        // Start with last digit and set its with 1 in the dp
        dp[K] = 1;
        
        int i;
        for (i = K - 1; i >= 0 ; i--)
        {
            // Compute dp[i]
            
            int curr_digit = s[i] - '0';
            for (string d : digits)
            {
                if (stoi(d) < curr_digit)
                {
                    dp[i] += pow(digits.size(), K-i-1);
                }
                else if (stoi(d) == curr_digit)
                {
                    dp[i] += dp[i+1];
                }
            }
        }
        
        // Recompte based on all dp contents
        for (i =  1; i < K; i++)
            dp[0] += pow(digits.size(), i);
        
        return dp[0];
        
        
        /*

                Details 
        Runtime: 0 ms, faster than 100.00% of C++ online submissions for Numbers At Most N Given Digit Set.
        Memory Usage: 8.5 MB, less than 25.34% of C++ online submissions for Numbers At Most N Given Digit Set.
        */
        
    }
};
