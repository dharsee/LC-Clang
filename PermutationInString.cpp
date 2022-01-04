/*

567. Permutation in String
Medium - 3972 - 111 - Add to List

Share
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.


*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);
        
        // Fill freq of each of the input strings
        
        int i, j, n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false;
        
        for (i = 0; i < n1; i++) {
            s1_freq[s1[i]-'a']++;
        }
        
        
        for (i = 0; i < n2 && i < n1; i++) {
            s2_freq[s2[i]-'a']++;
        }
        
        
        // Now check two freq counters
        for(j = 0; j < 26; j++) {
            if (s1_freq[j] != s2_freq[j]) break;
        }
        
        if (j == 26) return true;
        
        
        // now do a sliding window over the rest of the chars in s2
        while (i < n2) {
            // first take off old char from the freq
            s2_freq[s2[i-n1]-'a']--;
            
            // Now add new char
            s2_freq[s2[i]-'a']++;
            
            // Now check for pattern match
            // Now check two freq counters
            for(j = 0; j < 26; j++) {
                if (s1_freq[j] != s2_freq[j]) break;
            }
        
            if (j == 26) return true;
        
            i++;
        }
        
        return false;
    }
};

/*

Success
Details 
Runtime: 4 ms, faster than 97.43% of C++ online submissions for Permutation in String.
Memory Usage: 7.4 MB, less than 42.21% of C++ online submissions for Permutation in String.

*/
