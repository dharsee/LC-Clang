/*
Sequential Digits

Solution
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
   Hide Hint #1  
Generate all numbers with sequential digits and check if they are in the given range.
   Hide Hint #2  
Fix the starting digit then do a recursion that tries to append all valid digits.
*/

class Solution {
    
    inline int getLen(int num)
    {
        int k = num;
        int len = 2;
        while (k >= 10)
        {
            k /= 10;
            len++;
        }
        
        return len;
    }
    
    void generate(int curr_len, int tgt_len, int low, int high, int prev, int curr, vector<int> &res)
    {
        if (curr_len >= tgt_len)
        {
            if (curr <= high && curr >= low) res.push_back(curr);
            return;
        }
        
        if (prev == 9) return;
        
        curr = curr * 10;
        curr = curr + prev + 1;
        
        curr_len = curr_len + 1;
        prev = prev + 1;
        generate(curr_len, tgt_len, low, high, prev, curr, res);
        
    }
    
    void dump(vector<int> &res, int k)
    {
        int i, n = res.size();
        
        printf("\n i = %d ", k);
        for (i = 0; i < n; i++)
            printf(" %d ", res[i]);
        //printf("\n");
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        
        int i, j, k;
        vector<int> res;
               
        int slen = 0, elen = 0, m = 0, l = 0, len = 0;
    
        slen = getLen(low);
        elen = getLen(high);
        
        slen--;
        /* void generate(int curr_len, int tgt_len, int low, int high, int prev, int curr, vector<int> &res) */
        for (j = slen; j <= elen; j++)
        {
            for (i = 1; i < 9; i++)
            {
                generate(1, j, low, high, i, i, res);   
                //dump(res, i);
            }
        }
      
        return res;
    }
};
