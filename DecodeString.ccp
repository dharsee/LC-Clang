/*
394. Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

*/

class Solution {
public:
    string decodeString(string s) {
        
        int n = s.length();
        int i, j, k, l;
        
        //maintain 2 stacks to solve this problem
        
        stack<int> cnt;
        stack<string> res;
        
        string ans = "";
        
        i = 0;
        
        // Scan each char from the input string
        while (i < n)
        {
            if (s[i] == '[') // Open bracket
            {
                // Push on stack
                res.push(ans);
                ans = "";
                i++;
            }
            else if (s[i] == ']')
            {
                res.push(ans);
                ans = "";
                
                int counter = cnt.top();
                cnt.pop();
                
                string tempstr = res.top();
                res.pop();
                
                for (int k = 0; k < counter; k++) ans += tempstr;
                
                if (!res.empty())
                {
                    ans = res.top() + ans;
                    res.pop();
                }
                
                i++;
            }
            else if (s[i] - 'a' >= 0) // This is non-numeric char
            {
                // Just append this to the ans and move on
                ans += s[i];
                i++;
                
                
            }
            else
            {
                string str_count = "";
                // This is numeric char, need to handle it specially
                while (s[i] - 'a' <= -40)
                {
                    str_count += s[i];
                    i++;
                }
                
                int t = stoi(str_count);
                cnt.push(t);
                
            }
        } // End of while loop
        
        
        //
        return ans;
        
        /*
                Success
        Details 
        Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
        Memory Usage: 6.9 MB, less than 48.53% of C++ online submissions for Decode String.
        */
        
    }
};
