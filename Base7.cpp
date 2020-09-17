/*
504. Base 7
Easy

Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].

*/

class Solution {

    string reverse(string input)
    {
        int i = 0, n = input.length();
        if (n < 2) return input;
        
        int j = n - 1;
        
        while (i < j)
        {
            char c  = input[i];
            input[i] = input[j];
            input[j] = c;
            
            i++;
            --j;
        }
        return input;
    }
    
public:
    string convertToBase7(int num) {
     
        string res;
        
        if (num < 7 && num > -7) return to_string(num);
        
        int rem, k, neg = 0;
        
        k = num;
        if (num < 0)
        {
            neg = 1;
            k = -k;
        }
        
        while (k > 6)
        {
            rem = k % 7;
            k = k / 7;
            res += to_string(rem);
        }
        
        if (k != 0) res += to_string(k);
        
        if (neg)
        {
            return "-" + reverse(res);
        }
      
        return reverse(res);
        
    }
};

/*
Success
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Base 7.
Memory Usage: 5.9 MB, less than 84.54% of C++ online submissions for Base 7.
/*
