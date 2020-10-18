/*

Repeated DNA Sequences

Solution
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n = s.length();
        vector<string> res;
        
        if (n <= 9) return res;
        
        // Storing Patterns of 10 character sequence
        unordered_map<string, int> hmap;

        // Build hash map
        int i, count = 0;
        for (i = 0; i <= n - 10; i++)
        {
            string curr = s.substr(i, 10);
            //cout << endl << " Adding " << curr;
            hmap[curr]++;
            //cout << endl << " Adding " << curr;
        }
        
        // Build result by walking hash
        auto iter = hmap.begin();
        
        while (iter != hmap.end())
        {
            //cout << endl << " Pattern ( " << (*iter).first << ") --> Count = " << (*iter).second;
            if ((*iter).second > 1)
                res.push_back((*iter).first);
            
            iter++;
        }
        
        return res;
        
        
    }
    
    /*
            32 / 32 test cases passed.
        Status: Accepted
        Runtime: 88 ms
        Memory Usage: 23.7 MB
        Submitted: 0 minutes ago
  
    */
};
