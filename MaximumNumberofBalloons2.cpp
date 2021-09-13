/*
Maximum Number of Balloons

Solution
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:

Input: text = "nlaebolko"
Output: 1
Example 2:

Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.

*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int freq[26] = {0};
        
        // Fill frequency array by walking the input string
        
        int n1 = text.length();
        int i, j, k;
        // balloon
        if (n1 < 7) return 0;
        
        for (i = 0; i < n1; i++) {
            freq[text[i]-'a']++;
        }
        
        int a = freq[0];
        int b = freq[1];
        int l = freq['l'-'a'];
        int o = freq['o'-'a'];
        int n = freq['n'-'a'];
        
        int possible_count = min({a, b, l/2, o/2, n});
        
        return possible_count;
    }
};


/*

24 / 24 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 6.7 MB
Submitted: 0 minutes ago


*/
