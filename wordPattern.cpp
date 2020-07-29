/*
290. Word Pattern

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
    
    void split_words(string input, vector<string> &res)
    {
        int i = 0, n = input.size();
        
        string temp;
        while (i < n)
        {
            if (input[i] == ' ')
            {
                res.push_back(temp);
                temp = "";
            }
            else
                temp += input[i];
            i++;
        }
        res.push_back(temp);
    }
    
    void dump_words(vector<string> &res)
    {
        auto iter = res.begin();
        
        cout << endl << " Words -> ";
        while (iter != res.end())
        {
            cout << *iter << " ";
            iter++;
        }
        cout << endl;
    }
    
    bool wordPattern(string pattern, string str) {
        
        //break string to token by spaces 
        vector<string> res;
        
        split_words(str, res);
        
        //dump_words(res);
        
        set<string> st; //to maintain uniqueness of each word
        
        int i, n = pattern.length();
        
        if (n != res.size()) return false;
        
        unordered_map<char, string> hmap;
        
        // Build Hmap by scanning pattern
        
        
        for (i = 0; i < n; i++)
        {
            // first see if this is already seen
            if (hmap.find(pattern[i]) != hmap.end())
            {
                // Now check its new content and old content, return false if they dont match
                //if (hmap[pattern[i]] != res[i]) return false;
                if (res[i].compare(hmap[pattern[i]])) return false;
            }
            else // First time seen this mapping
            {
                // check in set if it appear then return false, this means same target is mapping more than single sourse
                if (st.find(res[i]) != st.end()) return false;
                
                // Else add it to map and set
                hmap[pattern[i]] = res[i];
                st.insert(res[i]);
                
            }
        }
        
        return true;
        
    }
};
