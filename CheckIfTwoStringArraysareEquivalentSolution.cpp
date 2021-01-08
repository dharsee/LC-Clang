/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.


*/


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
     
        //Find lengths of two vectors
        int len1 = 0, len2 = 0;
        string s1 = "", s2 = "";
        
        vector<string>::iterator iter1 = word1.begin();
        vector<string>::iterator iter2 = word2.begin();
        
        while (iter1 != word1.end() && iter2 != word2.end())
        {
            len1 += (*iter1).size();
            len2 += (*iter2).size();
            
            s1 += (*iter1);
            s2 += (*iter2);
            
            // Good optimization; Run time down to 4 sec from 12 sec
            if (s1.length() < s2.length()) 
            {
                if (s2.compare(0, s1.length(), s1) != 0) return false;
            }
            else 
            { 
                if (s1.compare(0, s2.length(), s2) != 0) return false ;
            }
            
            iter1++;
            iter2++;
        }
        
        // Left over if any
        while (iter1 != word1.end())
        {
            len1 += (*iter1).size();
            s1 += (*iter1);
            iter1++;
            
            // Good optimization; Run time down to 4 sec from 12 sec
            if (s1.length() < s2.length()) 
            {
                if (s2.compare(0, s1.length(), s1) != 0) return false;
            }
            else 
            { 
                if (s1.compare(0, s2.length(), s2) != 0) return false ;
            }
        }
        
        while (iter2 != word2.end())
        {
            len2 += (*iter2).size();
            s2 += (*iter2);
            iter2++;
            
            // Good optimization; Run time down to 4 sec from 12 sec
            if (s1.length() < s2.length()) 
            {
                if (s2.compare(0, s1.length(), s1) != 0) return false;
            }
            else 
            { 
                if (s1.compare(0, s2.length(), s2) != 0) return false ;
            }
        }
        
        if (len1 != len2) return false;
               
        return s1 == s2;
        
    }
};
