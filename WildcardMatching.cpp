/*

44. Wildcard Matching
Hard - 3894 - 170 - Add to List - Share
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/



class Solution {
public:
    bool isMatch(string s, string p) {
        
        // Using DP method
        // Declare a DP which covers s and p
        int slen = s.length();
        int plen = p.length();
        
        bool dp[slen+1][plen+1];
        
        memset(dp, 0, sizeof(dp));
        
        int i, j;
        
        // start with true, to indicate true for empty string and pattern
        dp[0][0] = true;
        
        // Take care of "*" in the pattern
        for (j = 1; j <= plen; j++) {
            if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
        }
        
        // Now scan DP starting with 1x1
        for (i = 1; i <= slen; i++) {
            for(j = 1; j <= plen; j++) {
                if (p[j-1] == '?' || (s[i-1] == p[j-1])) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else { /* not matching case */
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[slen][plen];
    }
};

/*

Success
Details 
Runtime: 36 ms, faster than 68.27% of C++ online submissions for Wildcard Matching.
Memory Usage: 7.8 MB, less than 73.10% of C++ online submissions for Wildcard Matching.

*/
