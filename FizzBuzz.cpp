/*

412. Fizz Buzz
Easy

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> res(n);
        if (n <= 0) return res;
        
        int i = 1;
        
        
        bool digit = false;
        while (i <= n)
        {
            digit = true;
            
            if (i%3 == 0)
            {
                res[i-1] += "Fizz";
                digit = false;
            }
            if (i%5 == 0)
            {
                res[i-1] += "Buzz";
                digit = false;
            }
                
            if (digit)
                res[i-1] += to_string(i);
            
            i++;
        }
        
        return res;
    }
};