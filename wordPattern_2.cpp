/*
Word Pattern

Solution
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.


*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<char, string> hmap;
        unordered_map<string, char> hmap2;
        
        int slen = str.length();
        int plen = pattern.length();
        
        if (slen == 0 && plen == 0) return false;
        if (slen == 0 && plen > 0) return false;
        if (slen > 0 && plen == 0) return false;
        
        int i, j = 0, k = 0, l = 0;
        
        for (i = 0; i < slen; i += k+1)
        {
            j = i;
            while (j < slen && str[j] != ' ') j++;
            
            k = j - i;
            string w = str.substr(i, k);
            //cout << endl << l <<  ". " << w << " (i, k) = " << i << ", " << k;
            
            if (l >= plen) return false;
            
            if (hmap.find(pattern[l]) != hmap.end())
            {
                //cout << " .. found pattern in hmap '" << hmap[pattern[l]] << "'";
                if (hmap[pattern[l]] != w) return false;
            }
            else if (hmap2.find(w) != hmap2.end())
            {
                if (hmap2[w] != pattern[l]) return false;
            }
            else
            {
                //cout << " .. could not find, adding this word with key '" << pattern[l] << "'"; 
                hmap[pattern[l]] = w;
                hmap2[w] = pattern[l];
            }
            
            l++;
            
            
        }
        
        
        
        if (l < plen || i < slen) return false;
        
        return true;
        
    }
};
