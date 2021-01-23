/*
Determine if Two Strings Are Close

Solution
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
Example 4:

Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.


*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        // Build frequency table for both words
        // track two chars that are differ (if exists)
        // If All the charactes are having same frequency then return TRUE
        
        // Case for having different in their frequency

        // Maintain two sets to know unique characters for word1 and word2
        
        // 1. Build frequency table
        
        vector<int> freq_w1(26, 0); 
        // 26 are good enough since input chars are only in lower case english letters
        vector<int> freq_w2(26, 0);
        
        set<char> sw1, sw2;
        
        int i, j;
        
        i = 0;
        int nw1 = word1.length(), nw2 = word2.length();
        
        if (nw1 != nw2) return false;
        
        while (i < nw1 && i < nw2)
        {
            freq_w1[word1[i]-'a']++;
            freq_w2[word2[i]-'a']++;
            
            sw1.insert(word1[i]);
            sw2.insert(word2[i]);
            
            i++;
        }
        
        // Left over from above combination
        
        while (i < nw1)
        {
            freq_w1[word1[i]-'a']++;
            sw1.insert(word1[i]);
            i++;
        }
        while (i < nw2)
        {
            freq_w2[word2[i]-'a']++;
            sw2.insert(word2[i]);
            i++;
        }
        
        // Sort frequency table to compare
        sort(freq_w1.begin(), freq_w1.end());
        sort(freq_w2.begin(), freq_w2.end());
        
        // Solution exists only when same set of chars and sorted frequency table matches
        if (sw1 == sw2 && freq_w1 == freq_w2) return true;
        
        // failure case
        return false;
    }
};


/*


144 / 144 test cases passed.
Status: Accepted
Runtime: 168 ms
Memory Usage: 20.7 MB
Submitted: 5 minutes ago

*/
