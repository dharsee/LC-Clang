/*
1189. Maximum Number of Balloons
Easy

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

1 <= text.length <= 10^4
text consists of lower case English letters only.

*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int freq[26] = {0};
        int i, n = text.length();
        
        if (n <= 6)
        {
            return 0;
        }
        
        for (i = 0; i < n; i++)
        {
            freq[text[i] - 'a']++;
        }
        
        int m = 0;
        
        /*
        a - 1
        b - 1
        l - 2
        o - 2
        n - 1
        TOTAL = 7
        */
        int lcount = freq['l' - 'a'];
        int ocount = freq['o' - 'a'];
        int acount = freq[0];
        int bcount = freq[1];
        int ncount = freq['n' - 'a'];
        
        
        return min({min(lcount/2, ocount/2), acount, bcount, ncount});
        
    }
    
    
    /* 
    Details 
Runtime: 4 ms, faster than 95.45% of C++ online submissions for Maximum Number of Balloons.
Memory Usage: 6.6 MB, less than 95.79% of C++ online submissions for Maximum Number of Balloons.
    */
};
