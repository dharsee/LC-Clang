/*
Reverse Only Letters

Solution
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.

*/

class Solution {
public:
    
    inline bool __isalpha(char ch) {
        
        if ( (ch >= 'a' && ch <= 'z') || 
             (ch >= 'A' && ch <= 'Z')) return true;
        
        return false;
        
    }
    
    string reverseOnlyLetters(string s) {
        int n = s.length();
        
        if(n <= 1) return s;
        
        int i, j, k, l;
        
        i = 0;
        j = n - 1;
        
        while (i < j) {
            // Move forward as long as curr position has non english lower case alphabet
            while (i < j && (!__isalpha(s[i]))) i++;
        
            // Move backward as long as curr position has non english lower case alphabet
            while (i < j && (!__isalpha(s[j]))) j--;
            
            if (i >= j) break;
            
            // Exchange i with j and move ahead
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            
            i++;
            j--;
        }
        
        return s;
    }
};


/*
115 / 115 test cases passed.
Status: Accepted
Runtime: 2 ms
Memory Usage: 5.9 MB
Submitted: 0 minutes ago


*/
