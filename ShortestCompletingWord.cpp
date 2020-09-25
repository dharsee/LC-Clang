/*
748. Shortest Completing Word
Easy

Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. 
Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", 
the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:

Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:

Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Example 3:

Input: licensePlate = "Ah71752", words = ["suggest","letter","of","husband","easy","education","drug","prevent","writer","old"]
Output: "husband"
Example 4:

Input: licensePlate = "OgEu755", words = ["enough","these","play","wide","wonder","box","arrive","money","tax","thus"]
Output: "enough"
Example 5:

Input: licensePlate = "iMSlpe4", words = ["claim","consumer","student","camera","public","never","wonder","simple","thought","use"]
Output: "simple"
 

Constraints:

1 <= licensePlate.length <= 7
licensePlate contains digits, letters (uppercase or lowercase) or space ' '.
1 <= words.length <= 1000
1 <= words[i].length <= 15
words[i] consists of lower case English letters.

*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        // Build grid (2D) of string according to length; each row will have same lenth words
        
        //1 <= words[i].length <= 15 -- According to this
        // 0th slot wont be used
        vector<vector<string>> wl(16, vector<string>()); // 16 - Since at most each ward will have 15 as in length
        
        // Build it 
        
        int i, n = words.size();
        
        for (i = 0; i < n; i++)
        {
            int len = words[i].length();
            wl[len].push_back(words[i]);
        }
        
        // Now build freq table for license plate's characters
        
        //int freq[26] = {0}; // In this case, it will be case ignored
        vector<int> freq(26, 0);
        int count = 0;
        
        int k = licensePlate.length();
        for (i = 0; i < k; i++)
        {
            if (licensePlate[i] >= '0' && licensePlate[i] <= '9') continue;
            if (licensePlate[i] == ' ') continue;
            freq[tolower(licensePlate[i]) - 'a']++;
            count++; // This will represent number of characters license plate has
        }
        
        // We can start from same lenth of characters' length from the license plate to optimize, since it wont be possible to have in lesser len words.
        for (i = count; i <= 15; i++)  // 15 rows
        {
            int j, len = wl[i].size();
            
            for (j = 0; j < len; j++) // Cols, interms of words
            {
                int curr_count = count;
                vector<int> l_freq(freq);
            
                string s = wl[i][j];
                int l = s.length();
                for (int m = 0; m < l; m++) // for the current word
                {
                    //if (freq[s[m] - 'a']) curr_count--;
                    if (l_freq[s[m] - 'a'] > 0)
                    {
                        curr_count--;
                        l_freq[s[m] - 'a']--;
                        
                    }
                }
                //cout << endl << " Word = " << s << "  curr_count = " << curr_count << " count = " << count;
                if (curr_count == 0) return s;
            }
        }
        
        // It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
        // According to the problem statement, answer should exist. we dont come here any time, but to make compile happy
        return "Sould not";
        
    }
    
    
    /*
    102 / 102 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 15.7 MB
Submitted: 1 minute ago

    
    */
};
