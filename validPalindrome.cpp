/*
Valid Palindrome

Solution
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

*/

class Solution {
    
    inline bool isLower(char ch)
    {
        if (ch >= 'a' && ch <= 'z') return true;
        return false;
    }
    
    inline bool isUpper(char ch)
    {
        if (ch >= 'A' && ch <= 'Z') return true;
        return false;
    }
    
    inline bool isNumeric(char ch)
    {
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
    
    inline bool isIgnorable(char ch)
    {
        if (isLower(ch) || isUpper(ch) || isNumeric(ch)) return false;
        
        return true;
    }
    
    
public:
    bool isPalindrome(string s) {
        
        int n = s.length();
        
        if (n == 0) return true;
        
        int i, j;
        
        i = 0, j = n - 1;
        
        while (i < j)
        {
            //printf("\n '%c - %c' ", s[i], s[j]);
            if (isIgnorable(s[i]))
            {
                i++;
                continue;
            }
            
            if (isIgnorable(s[j]))
            {
                j--;
                continue;
            }
            
            char l = isLower(s[i]) ? s[i] : (isUpper(s[i]) ? s[i] + 32 : s[i]);
            char r = isLower(s[j]) ? s[j] : (isUpper(s[j]) ? s[j] + 32 : s[j]);
           
            //printf(" ---  '%c - %c' ", l, r);
            if (l != r) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};
