/*
470. Implement Rand10() Using Rand7()
Medium

Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

 

Example 1:

Input: 1
Output: [7]
Example 2:

Input: 2
Output: [8,4]
Example 3:

Input: 3
Output: [8,1,10]
 

Note:

rand7 is predefined.
Each testcase has one argument: n, the number of times that rand10 is called.
 

Follow up:

What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?

*/


// Aprroach #1

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        
        int r, c, index = 50;
        
        
        while (index > 40)
        {
            r = rand7();
            c = rand7();
            
            index  = c + (r - 1) * 7;
        }
        
        return (index - 1) % 10 + 1; // Since range is 1 - 10
        
    }
};



//Approach #2

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        
        int f = rand7();
        int s = rand7();
        
        // if first one comes more than 5 then re-dial until u get with 5
        while (f > 5) f = rand7();
        
        // if second one comes more than 6 then re-dial until u get with 6
        while (s == 7) s = rand7();
        
        return (s <= 3) ? f : f + 5;
        
    }
};
