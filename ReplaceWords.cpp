/*
648. Replace Words

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
Example 3:

Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
Output: "a a a a a a a a bbb baba a"
Example 4:

Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 5:

Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
Output: "it is ab that this solution is ac"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 10^6
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Each two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

*/



#include <algorithm>
#include <functional>
#include <string>


class Solution {
public:
    
    /**
 * @brief Right Trim
 *
 * Trims whitespace from the right end of the provided std::string
 *
 * @param[out] s The std::string to trim
 *
 * @return The modified std::string&
 */
std::string& rtrim(std::string& s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
    std::ptr_fun<int, int>(std::isgraph)).base(), s.end());
  return s;
}
    
    string replaceWords(vector<string>& dictionary, string sentence) {
     
        string res;
        
        // BUILD set with dictionary words
        set<string> set_dict;
        
        auto iter = dictionary.begin();
        
        while (iter != dictionary.end()) {
            set_dict.insert(*iter);
            iter++;
        }
        
        int i = 0, k = 0;
        int sz = sentence.length();
        
        while (i < sz) {
            // k = 0;
            string temp_str = "";
            bool inserted = false;
            while (i < sz && sentence[i] != ' ') {

                temp_str.push_back(sentence[i]);

                // cout << endl << "Working on [" << temp_str << "]";
                if (set_dict.find(temp_str) != set_dict.end()) {
            
                    // cout << " Matched .. Adding  [" << temp_str << "]";
                    res.append(temp_str);
                    res.append(" ");
                    inserted = true;
                    // Advance till next word;
                    while (i < sz && sentence[i] != ' ') i++;
                    //temp_str = " ";
                    //i--;
                    break;
                }
                
                i++;
            }
            
            if (temp_str.empty()) continue;
            if (!inserted) {
                // cout << endl << " (Out of loop) Adding = [" << temp_str << "] k = " << k;
                res.append(temp_str);
                res.append(" ");
            }
            i++;
        }
        
        // Need to remove trailing space
        
        res = rtrim(res);  
        return res;
    }
};

/*
Success
Details 
Runtime: 368 ms, faster than 14.42% of C++ online submissions for Replace Words.
Memory Usage: 23.1 MB, less than 88.98% of C++ online submissions for Replace Words.

*/
