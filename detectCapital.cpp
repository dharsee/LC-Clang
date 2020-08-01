/*
Detect Capital

Solution
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.


*/


class Solution {
    static bool islower(char c)
    {
        if (c >= 'a' && c <= 'z') return true;
        return false;
    }
    
    static bool isupper(char c)
    {
        if (c >= 'A' && c <= 'Z') return true;
        return false;
    }
    
    static bool alllower(string word, int start)
    {
        int n = word.length();
        
        
        while (start < n - 1)
        {
            if (islower(word[start + 1]) != islower(word[start])) return false;
            start++;
        }
        
        return true;
    }
    
    static bool allupper(string word, int start)
    {
        int n = word.length();
        
        
        while (start < n - 1)
        {
            if (isupper(word[start+1]) != isupper(word[start])) return false;
            start++;
        }
        
        return true;
    }
    
    
public:
    /*
    enum
    {
        LOWER = 0,
        UPPER = 1,
        MIXED = 2
    } Case;
    */
    
    
    bool detectCapitalUse(string word) {
        
        int n = word.length();
        
        if (n <= 1) return true;
        
        
        bool first = false; // FALSE denotes lower case letter
        bool second = false; // LOWER
        bool upper = false;
        bool lower = false;
        
        // RULE 
        // 1. if word starts with UPPER and all remaining letters are upper then correct
        // 2. if word starts with UPPER and all remaining letters are lower case then correct
        // 3. all letters are in lowe case then correct
        
        first = islower(word[0]);
        second = islower(word[1]);
        
        if (first == second) // both are lower/upper and same
        {
            if (first)
                return alllower(word, 1);
            else
                return allupper(word, 1);
        }
        else
        {
            if (first == true && second == false) // is lower
                return false;
            if (first == false) // UPPER
            {
                if (alllower(word, 1)) return true;
                else return allupper(word, 1);
            }
        }
        
        // Should not but to make compile happy
        printf("\n Why ???? ");
        return false;
    }    
        
};
