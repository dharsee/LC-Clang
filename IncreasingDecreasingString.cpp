/*
1370. Increasing Decreasing String
Easy

Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

 

Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
Example 3:

Input: s = "leetcode"
Output: "cdelotee"
Example 4:

Input: s = "ggggggg"
Output: "ggggggg"
Example 5:

Input: s = "spo"
Output: "ops"
 

Constraints:

1 <= s.length <= 500
s contains only lower-case English letters.

*/

class Solution {
public:
    
    void dumpf(int *freq)
    {
        int i = 0;
        
        for (i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
                printf("\n %c --> %d", i+'a', freq[i]);
        }
        
    }
    
    string sortString(string s) {
        
        
        int n = s.length();
        int i;
        
        int freq[26] = {0}; // Freq table for lower-case alphabets
        
        //BUILD freq table
        
        for (i = 0; i < n; i++)
        {
            freq[s[i]-'a']++;
        }
        
        //dumpf(freq);
        
        string res;
        
        while (1)
        {
            bool found = false;
            char last_char = 'A';
            bool first_char = true;
            
            // Increasing seq
            for (i = 0; i < 26; i++)
            {
                int curr_char = i + 'a';
                if (freq[i] > 0)
                {
                    if (first_char) // JUST Append
                    {
                        res += char(curr_char);
                        freq[i]--;
                        last_char = curr_char;
                        found = true;    
                        first_char = false;
                    }
                    else if (curr_char > last_char) 
                    {
                        res += char(curr_char);
                        freq[i]--;
                        last_char = curr_char;
                        found = true;    
                    }
                }
            }
            
            first_char = true;
            // Decreasing Seq
            
            for (i = 25; i >= 0; i--)
            {
                int curr_char = i + 'a';
                if (freq[i] > 0)
                {
                    if (first_char)
                    {
                        res += char(curr_char);
                        freq[i]--;
                        last_char = curr_char;
                        found = true;  
                        first_char = false;
                    }
                    else if (curr_char < last_char)
                    {
                        res += char(curr_char);
                        freq[i]--;
                        last_char = curr_char;
                        found = true;   
                    }
                }
            }
            
            if (!found) break;
        }
        
        return res;
    }
    
    
    /*
    
            Success
        Details 
        Runtime: 4 ms, faster than 99.38% of C++ online submissions for Increasing Decreasing String.
        Memory Usage: 7.6 MB, less than 5.70% of C++ online submissions for Increasing Decreasing String.
    */
};
