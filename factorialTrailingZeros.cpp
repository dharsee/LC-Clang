/*
172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.

For proof : https://www.purplemath.com/modules/factzero.htm

*/
class Solution {
public:
    int trailingZeroes(int n) {
        
        /*
        Basic logic would be count trailing zero for each of mutliple of 5 and its exponents
        like, 5, 5^2 = 25, 5^3 = 125, 5^4 = 625 ...etc
         */  
    
        int k = 5;
        int count = 0;
        
        /*
        while (k <= n)
        {
            count += n / k;
            
            if (INT_MAX/5 > k) // This is to handle INT overflow
                k = k * 5;
            else 
                return count;
        }
        */
    
        // To get rid of Inteoverflow check in loop
        // start with dividing num by 5 cnad keep continute
        // in this case 25/5 = 5 and then 5/5 = 1 (1+6)
        // like that for every multiple of 5
        
        while (n >= 5)
        {
            count += n/5;
            n /= 5;
        }
        
        return count;
        
        /*
        int fives = n / 5;
        int twentyfives = n /25;
        int onetf = n / 125;
        int sixtf = n / 625;
        int f = n /(5*625);
        
        return fives + twentyfives + onetf + sixtf + f;
        */
    }
};

