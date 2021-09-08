/*
Shifting Letters

Solution
You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
Example 2:

Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
 
Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
shifts.length == s.length
0 <= shifts[i] <= 109

*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        string res;
        
        
        int n = s.length();
        int i, j, k;
        
        
        for (i = n-2; i >= 0; i--) {
            shifts[i] = shifts[i] % 26 + shifts[i+1] % 26;
        }
        
        for (i = 0; i < n; i++) {
            int alpha = s[i] - 'a';
            int mv = shifts[i] % 26;
            
            alpha = (alpha + mv) % 26;
            char ch = 'a' + alpha;
            
            //cout << endl << " Input = " << s[i] << " New = " << ch;
            res.push_back(ch);
        }
        
        return res;
    }
};

/*
53 / 53 test cases passed.
Status: Accepted
Runtime: 196 ms
Memory Usage: 69.7 MB
Submitted: 38 minutes ago




*/
