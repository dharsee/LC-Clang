/*
1408. String Matching in an Array
Easy

Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.

*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
        if (n == 1) return {""};
        
        int i, j;
        vector<string> res;
        
        // This is O(N^2) solution where N - length of the vector
        
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    std::size_t found = words[j].find(words[i]);
                    if (found != std::string::npos) //FOUND SUBSTRING
                    {
                        res.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        
        /*
        The way to search word in the input string
        std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';
        */
        
      
        /*
                Success
        Details 
        Runtime: 4 ms, faster than 97.84% of C++ online submissions for String Matching in an Array.
        Memory Usage: 8.7 MB, less than 5.56% of C++ online submissions for String Matching in an Array.
        */
        return res;
    }
};
