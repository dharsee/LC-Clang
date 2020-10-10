/*
1002. Find Common Characters
Easy

Given an array A of strings made only from lowercase letters, return a list of all characters that 
show up in all strings within the list (including duplicates).  
For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 
Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter

*/

class Solution {
public:
    
    void dump(vector<vector<int>> &freq_table)
    {
        int n = freq_table.size();
        int i;
        
        for (i = 0; i < n; i++)
        {
            int j = 0;
            printf("\n");
            while (j < 26)
            {
                if (freq_table[i][j] > 0)
                {
                    printf(" <%c - %d>", 'a' + j, freq_table[i][j]);
                }
                j++;
            }
        }
    }
    
    vector<string> commonChars(vector<string>& A) {
        
        int n = A.size();
        
        // n X 26 table to hold count of each char in the string
        vector<vector<int>> freq_table(n, vector<int>(26, 0));
        
        // BUILD freq table by scanning input string
        int i, j, k;
        
        for (i = 0; i < n; i++)
        {
            j = A[i].length();
            k = 0;
            while (k < j)
            {
                freq_table[i][A[i][k] - 'a']++;
                k++;
            }
        }
        
        //dump(freq_table);
        
        // Now build result
        vector<string> res;
        
        // Scan for each alphabet and see if it is present in all input string and how many times
        for (j = 0; j < 26; j++)
        {
            int m = INT_MAX;
            
            for (i = 0; i < n; i++)
                m = min(m, freq_table[i][j]);
            
            // Insert this char m times into the result string vector
            while (m > 0)
            {
                string curr(1, 'a' + j);
                res.push_back(curr);
                m--;
            }
        }
        
        return res;
        
    }
    
    /*
    Success
Details 
Runtime: 12 ms, faster than 89.94% of C++ online submissions for Find Common Characters.
Memory Usage: 10.1 MB, less than 5.55% of C++ online submissions for Find Common Characters.
    
    */
};
