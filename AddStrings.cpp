/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 
Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/


class Solution {
public:
    
    string workon(string num1, string num2){
        // int i = 0, j = 0, num = 0, counter = 0;
        string res = "";
        
        // Find length of each input strings
        int slen1 = num1.length();
        int slen2 = num2.length();
        
        if (slen1 == 0) return num2;
        else if (slen2 == 0) return num1;
        
        // Start iterating from the end of input string
        slen1--;
        slen2--;
        int carry = 0;
        while (slen1 >= 0 && slen2 >= 0) {
            int n1 = num1[slen1] - '0';
            int n2 = num2[slen2] - '0';
            // cout << "<" << n1 << "," << n2 << "> ";
            int sum = carry + n1 + n2;
            if (sum > 9) {
                res += to_string(sum % 10);
                carry = sum / 10;
            } else {
                res += to_string(sum);
                carry = 0;
            }
            
            --slen1;
            --slen2;
            // cout << "res = " << res << "sum = " << sum << endl;
        }
        
        // Check for left ove in num1
        while (slen1 >= 0) {
            int sum = carry + num1[slen1] - '0';
            if (sum > 9) {
                res += to_string(sum % 10);
                carry = sum / 10;
            } else {
                res += to_string(sum);
                carry = 0;
            }
            --slen1;
        }
        
        
        // Check for left ove in num2
        while (slen2 >= 0) {
            int sum = carry + num2[slen2] - '0';
            if (sum > 9) {
                res += to_string(sum % 10);
                carry = sum / 10;
            } else {
                res += to_string(sum);
                carry = 0;
            }
            
            --slen2;
        }
        
        if (carry) res += to_string(carry);
        
        // Now reverse the result string and sent it back.
        std::reverse(res.begin(), res.end());
        
        return res;
    }
    
    string addStrings(string num1, string num2) {
        return workon(num1, num2);
    }
};


/*

317 / 317 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 6.9 MB
Submitted: 0 minutes ago

*/
