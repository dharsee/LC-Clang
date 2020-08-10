/*
Excel Sheet Column Number

Solution
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

*/


class Solution {
public:
    int titleToNumber(string s) {
        
        // Since I know the upper limit of the input, I build target powers of 26 in that static arrays
        // This is improve the runtime
        int t26powers[7] = {1, 26, 676, 17576, 456976, 11881376, 308915776};
               
        /*
        i = 0 res = 1
        i = 1 res = 26
        i = 2 res = 676 
        i = 3 res = 17576 
        i = 4 res = 456976 
        i = 5 res = 11881376 
        i = 6 res = 308915776 
        */
        
        int res = 0;
        int i = 0;
        int n = s.length();
        --n;
        
        while (n >= 0)
        {
            res = res + ((s[n] - 'A' + 1) * t26powers[i]);
            //printf("\n i = %d res = %d ", i+1, res);
            n--;
            i++;
        }
       
        return res;
    }
};
