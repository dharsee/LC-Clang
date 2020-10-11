/*
1081. Smallest Subsequence of Distinct Characters
Medium

Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/


/*
This is duplicate of the problem
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3491/
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        
        // Using the same solution that was used for 
        //
        // Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
        
        int n = s.length();
        if (n == 0) return "";
        if (n == 1) return s;
        
        int seen[26] = {0}; // This will represent whether char is prensent on the stack or not
        // 0 - indicates not present; 1 - indicates present on the stack
        
        int last_seenAt[26] = {-1};
        // This array will have index of each char when it was seen last time
        
        // Fill the last_seenAt by reading input string
        int i = 0;
        while (i < n)
        {
            last_seenAt[s[i] - 'a'] = i;
            i++;
        }

        stack<char> st; // to maintain lexicograpical order or chars
        
        
        // Now scan input string to fill the stack
 
        for(i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            
            if (seen[index]) continue; // Which means this char is present on the stack
            
            while (!st.empty() && st.top() > s[i] && i < last_seenAt[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = 0; //since we are removing this char
                st.pop();
            }
            
            st.push(s[i]);
            seen[index] = 1;
            
        }
        
        // Now build the result string in the reverse order
        
        int sz = st.size();
        string res(sz, '0');
        
        i = sz - 1;
        while (!st.empty())
        {
            res[i] = st.top();
            st.pop();
            i--;
        }
        
        return res;
    }
    
    
    /*
    
    Success
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Subsequence of Distinct Characters.
Memory Usage: 6.6 MB, less than 46.64% of C++ online submissions for Smallest Subsequence of Distinct Characters.
    
    */
};
