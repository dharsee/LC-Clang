/*
763. Partition Labels
Medium

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.

*/


class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> res;
        int n = S.length();
        if (n <= 0) return res;
        
        // Build index table for possible input chars (lower case english alphabet )
        int last_index[26] = {0}; // since possible input chars are only lower case english alphabet
        
        int i = 0;
        
        while (i < n)
        {
            last_index[S[i] - 'a'] = i;
            i++;
        }
        
        
        
        int start = 0, j = 0;
        i = 0;
        
        while (i < n)
        {
            j = max(j, last_index[S[i] - 'a']);
            if (i == j)
            {
                res.push_back(i - start + 1);
                start = i + 1;
            }
            
            i++;
        }
        
        return res;
        
    }
};
