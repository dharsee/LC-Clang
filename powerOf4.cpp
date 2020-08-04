/*
Power of Four

Solution
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    
    
    // More efficient approach to check PowerofFour or not.
    
    /*
     Approach 1 :
     Given number is power of 4 only when
         1. If number is power of 2 AND
         2. num % 3 == 1
    
    === >>>> How to check number is power of 2 or not
    if the number is power of 2 then it must have only one set bit, if you can clear 
    that bit then result must be zero
    
    n & (n - 1) ====> this will clear MSB set bit of the number 
    
    (n & (n-1)) == 0 only when number is power of 2
    
    */
    /*
    bool isPowerOfFour(int num) {
    
        if (num < 0) return false;
        
        if ((num & (num - 1)) == 0) // power of 2
        {
            if (num % 3 == 1) return true;
            else return false;
        }
        return false;
    }
    */
    
    /*
     Approach 2 :
     Given number is power of 4 only when
         1. If number is power of 2 AND
         2. its only set bit must be at even position
    */
    
    bool isPowerOfFour(int num) {
    
        if (num <= 0) return false;
        
        if ((num & (num - 1)) == 0) // power of 2
        {
            // To test set bit position at even use this mask (0xA)
            int mask = 0xAAAAAAAA;
            
            if ((num & mask) == 0) return true;
            
            else return false;
        }
        return false;
    }
    
    
    #if 0
    // These two solutions are like brute force methods.
    // Recursive Solution
    bool isPowerOfFour(int num) {
              
        if (num < 0) return false;
        if (num == 0) return false;
        if (num == 1) return true;
        
        int rem = num % 4;
        
        if (rem) return false;
        
        return isPowerOfFour(num/4);
    }
    
    // Loop Based Solution
    bool isPowerOfFour(int num) {
              
        if (num < 0) return false;
        if (num == 0) return false;
        if (num == 1) return true;
        
        // LOOP
        int rem = 0;
        
        rem = num % 4;
        while (num>1)
        {
            rem = num % 4;
            if (rem) return false;
            num /= 4;
        }
        
        return rem == 0;
    }
    #endif
};
