/*
Length of Last Word

Solution
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5


*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        
        int n = s.length();
        
        if (n == 0) return 0;
        if (n == 1 && s[0] != ' ') return 1;
        
        int i = n - 1, len = 0;
        
        // Remove trailing spaces if any
        while (i >= 0 && s[i] == ' ') i--;
        
        while (i >= 0)
        {
            if (s[i] == ' ') break;
            len++;
            i--;
        }
        
        return len;
    }
};
