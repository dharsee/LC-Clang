/*
720. Longest Word in Dictionary
Easy

Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].

*/

// BRUTE-FORCE method 
// Runtime O(N^2)


class Solution {
public:
    
    void dump(vector<string>& words)
    {
        int n = words.size(), i;
        
        //printf("\n");
        for (i = 0; i < n; i++)
            cout << words[i] << " ";
        
    }
    
    string longestWord(vector<string>& words) {
        
        int n = words.size(), i = 0, j = 0;
        
        if (n == 0) return "";
        
        /*
        printf("\nInput  ->  :");
        dump(words);
        */
        
        
        // it would be easy if we sort the input then process, but it would cost us O(NlogN)
        // We could avoid this, since we have added the map to find them with O(1) at an average
        // But we need to add one more check before deciding result candidate.
        
        //sort(words.begin(), words.end());
        
        unordered_map<string, int> hmap;
        for (i = 0; i < n; i++)
            hmap[words[i]]++;
        
        /*
        printf("\nSorted  ->  :");
        dump(words);
        */
        
        int max_len = 0;
        string max_str;
        
        for (i = 0; i < n; i++)
        {
            int curr_len = words[i].length();
            bool good_candidate = true;
            for (j = 0; j < curr_len - 1; j++)
            {
                string ts = words[i].substr(0, j+1);
                
                // If prefix is not present
                if (hmap.find(ts) == hmap.end()) 
                {
                    good_candidate = false;
                    break;
                }
            }
            
            if (good_candidate)
            {
                //cout << endl << "Good candidate -> " << words[i] << " Previous one -> " << max_str << " " << curr_len << ":" << max_len << ", " << (max_str < words[i]) ? 1 : 0;
                
                if (max_str == "")
                {
                    max_str = words[i];
                    max_len = curr_len;
                }
                else if (curr_len >= max_len) 
                {
                    if (curr_len == max_len)
                    {
                        if (max_str > words[i])
                        {
                            // This is needed since input vector wasn't sorted
                            max_str = words[i];   
                        }
                    }
                    else
                    {
                        max_len = curr_len;
                        max_str = words[i]; 
                    }
                }
            }
            
        }
        
        
        return max_str;
        
    }
};

/*
57 / 57 test cases passed.
Status: Accepted
Runtime: 156 ms
Memory Usage: 31.1 MB
Submitted: 5 minutes ago



*/
