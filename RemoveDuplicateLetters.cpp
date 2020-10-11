/*
Remove Duplicate Letters

Solution
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.


Hide Hint #1  

Greedily try to add one missing character. How to check if adding some character will not cause problems ? 
Use bit-masks to check whether you will be able to complete the sub-sequence if you add the character at some index i.

*/

class Solution {
public:
    
    void reverse(string &input)
    {
        int n = input.length();
        
        int l = 0, h = n - 1;
        
        while (l < h)
        {
            char c = input[l];
            input[l] = input[h];
            input[h] = c;
            
            h--;
            l++;
        }
    }
    
    
    string removeDuplicateLetters(string s) {
        
        int n = s.length();
        if (n == 0) return "";
        if (n == 1) return s;
        
        stack<char> st; // Maintain stack to keep the lexicographical order among already see chars
        int seen[26] = {0}; // This will tell us that whether current char is present in the stack or not
        // 0 indicates unseen and 1 indicates seen
        
        int last_seenAt[26] = {-1}; // This will track last index of purticular char in the string
        int i = 0;
        
        // Fill last Index of the char {at max we will have 26 characters}
        while (i < n)
        {
            last_seenAt[s[i]-'a'] = i;
            i++;
        }
        
        
        
        // Scan input array to build the stack with lexicographical order
        for (i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            
            if (seen[index]) continue; // since this char is already present in the stack
            
            while (!st.empty() && st.top() > s[i] && i < last_seenAt[st.top()-'a'])
            {
                seen[st.top()-'a'] = 0;
                st.pop();
            }
            
            st.push(s[i]);
            seen[index] = 1;
        }
        
        
        string res;
        // Build result string
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res);
        return res;
        
        
        /*
            289 / 289 test cases passed.
            Status: Accepted
            Runtime: 0 ms
            Memory Usage: 6.8 MB
            Submitted: 0 minutes ago


        */
    }
};
