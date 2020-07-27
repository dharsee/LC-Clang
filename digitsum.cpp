/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

For proof : https://en.wikipedia.org/wiki/Digital_root
*/

class Solution {
public:
    
    /*
    // As per mathmatical proof of digitalroot given in the solution 
    Approach 1: Mathematical: Digital Root
    Formula for the Digital Root

There is a known formula to compute a digital root in a decimal numeral system

 (n)=0,if n=0

 (n)=9,if n=9k

 (n)=nmod9,if n != 9k
      */  
    
    int addDigits(int n) {
    
        if (n == 0) return 0;
        if (n % 9 == 0) return 9;
        return n % 9;
    }
    
    #if 0
    
    int addDigits(int num) {
    
        if (num < 10) return num;
        
        // create hash map
        unordered_map<int, int> hmap;
        
        int i, j;
        
        for (i = 1; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                int indx = i * 10 + j;
                hmap[indx] = (i+j)%10;
                hmap[indx] += (i+j) > 9 ? 1 : 0;
            }
        }
        
        /*
        // Dump hamp
        auto iter = hmap.begin();
        i = 1;
        printf("\n Len of hmap = %d \n", hmap.size());
        while (iter != hmap.end())
        {
            if (i % 11 == 0) printf("\n");
            //printf(" %2d = %2d", *(iter)->first, *(iter)->second);
            //printf(" %2d = %2d", (*iter)->first, (*iter)->second);//
            printf(" %2d = %2d", (*iter).first, (*iter).second);
            iter++;
            i++;
            
        }
        */
        
        // Now convert to string to prosess
        
        string s;
        s = to_string(num);
        
        // Now process string one at a time
        int carry = s[0]-'0';
        
        i = 1;
        int n = s.length();
        
        while (i < n)
        {
            
            carry = carry * 10 + s[i] - '0';
            carry = hmap[carry];
            //sum += carry;
            //printf("\n i = %d Carry = %d n = %d", i, carry, n);
            i++;
        }
        
        return carry;
        
    }
    
    #endif
    
    #if 0
    // Naive approach
    
    int addDigits(int num) {
        
        int sum = 0, rem = 0;
        int curr = 0;
        
        sum = num;
        while (sum > 9)
        {
            curr = sum;
            sum = 0;
            while (curr)
            {
              sum += (curr % 10);
                curr /= 10;
            }
        }
        
        return sum;
        
    }
    #endif
    
};
