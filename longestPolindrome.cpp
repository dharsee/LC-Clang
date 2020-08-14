/*
Longest Palindrome

Solution
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/
class Solution {
public:
    int longestPalindrome(string s) {
        
        // Maintain a count table / freq table for lower/upper case english letters
        // take one single occurance letter and count it
        // for every highier count letter count max of even number 
        // do this for every letter that is present in the input string 
        
        
        int freq[52] = {0}; // 26 + 26
        // Lower letters from 0 - 25 and 26 - 51
        // lower l-'a'
        // upper l-'A' + 25
        
        // Lets build this frequency table
        
        int n = s.length();
        int i;
        
        for (i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                freq[s[i] - 'a']++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                freq[s[i] - 'A' + 25]++;
            }
        }
        
        
        // Now scan freq table to get largest possible lenght of string that can be build with this input string
        bool single = false;
        bool odd_len = false;
        
        int count = 0;
        
        for (i = 0; i < 52; i++)
        {
            if (freq[i] == 0) continue;
            
            if (freq[i] == 1)
                single = true;
            else if (freq[i] & 0x1)
            {
                odd_len = true;
                count += freq[i]-1;
            }
            else
                count += freq[i];
                
        }
        
        //
        if (single || odd_len) count++;
        
        return count;
        
    }
};
