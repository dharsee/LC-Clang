/*
Repeated Substring Pattern

Solution
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int len = s.length();
        int n = 0;
        
        for (n = len/2; n > 0; n--)
        {
            // This check is important, we dont want to process when len is not multiple of n
            if (len % n) continue;
            
            int k = 0;
            while ((k + n) < len && s[k] == s[k+n]) k++;
            
            if (k + n == len) return true;
        }
        
        return false;
        
    }
};
