/*
Maximum Length of a Concatenated String with Unique Characters

Solution
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
*/


class Solution {
public:
    
    bool hasUniqueChars(string &s) {
        int n = s.length();
        
        if (n <= 1) return true;
        else if (n > 26) return false;
        
        int freq[26] = {0};
        int i;
        
        for (i = 0; i < n; i++) {
            if (freq[s[i]-'a']) return false;
            freq[s[i]-'a']++;
        }
        
        return true;
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        
        vector<string> res;
        int maxlen = 0;
        
        // Add Empty string to the res set to start
        res.push_back("");
        
        int i, j, k, l;
        
        for (i = 0; i < n; i++) {
            
            // first see if there are any duplicates within the current string
            if (!hasUniqueChars(arr[i])) continue; // Skip it to the candidate list
            
            // Now compare with res set and append if they form unique combination
            int m = res.size();
            for (j = 0; j < m; j++) {
                // We know that candidates from res set are unique un nature
                string temp;
                
                temp.append(res[j]).append(arr[i]);
                if (!hasUniqueChars(temp)) continue;
                
                // This became a candidate in the res list
                if (maxlen < temp.length()) maxlen = temp.length();
                
                res.push_back(temp);
            }
        
        }
        
        return maxlen;
    }
};



/*

85 / 85 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 13.9 MB
Submitted: 0 minutes ago

*/
