/*
 Break a Palindrome

Solution
Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

 

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
Example 2:

Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
Example 3:

Input: palindrome = "aa"
Output: "ab"
Example 4:

Input: palindrome = "aba"
Output: "abb"
 

Constraints:

1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters.
   Hide Hint #1  
How to detect if there is impossible to perform the replacement? Only when the length = 1.
   Hide Hint #2  
Change the first non 'a' character to 'a'.
   Hide Hint #3  
What if the string has only 'a'?
   Hide Hint #4  
Change the last character to 'b'.


*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.length();
        int i;
        
        if (n == 1) return "";
       
        int index = 0;
        int acount = 0;
        
        // Assuming given input string is palindrome
        for (i = 0; i < n; i++) {
            
            if (palindrome[i] == 'a') { index = i; acount++; }
            else break;
        }
        // means all are 'a's
        if (i == n) { 
            palindrome[n-1] = 'b';
            return palindrome;
        }
        
        // if (i is not at the center)
        if (i != n / 2)    
            palindrome[i] = 'a';
        else { // it was at center
            
            // Look for 'a' in the rest of the part from the last postion
            // if you find a, then change it to 'b' and return
            for (int j = n-1; j > i; j--)
            {
                if (palindrome[j] == 'a') {
                    palindrome[j] = 'b';
                    return palindrome;
                }
            }
            
            // If you dont find 'a' in the rest of the string then replace current char with next possible char
            palindrome[i+1]++;
            
        }
        
        return palindrome;
        
        
        
    }
};

/*
30 / 30 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 6.1 MB
Submitted: 0 minutes ago

*/
