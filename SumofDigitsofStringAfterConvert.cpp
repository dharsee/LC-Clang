/*
1945. Sum of Digits of String After Convert
User Accepted:5750
User Tried:6304
Total Accepted:5882
Total Submissions:9421
Difficulty:Easy
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
Example 3:

Input: s = "zbax", k = 2
Output: 8
 

Constraints:

1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.

*/


#include <string>
class Solution {
public:
    string convert(string &s)
    {
        int i = 0, sz = s.length();
        
        string res;
        
        while (i < sz) {
            res.append(to_string(s[i]-'a'+1));
            i++;
        }
        
        return res;
    }
    
    int getLucky(string s, int k) {
        
        
        string res = "";
        int temp = 0;
        
        string sres = convert(s);
        //cout << endl << " Input = " << s << " After Convert = " << sres << endl;
        
        // int sz = sres.length();
        int i = 0;
        while (i < k) {
            res = "";
            
            int sz = sres.length();
            
            temp = 0;
            for (int j = 0; j < sz; j++) {
                temp = temp + sres[j]-'0';
                
            }
            
            res = to_string(temp);
            sres = res;
            i++;
            //cout << endl << " After " << i << "th pass = " << sres;
            
        }        
        
        // Just convert string to int to return
        
        // cout << endl << " After K passes = " << sres << endl;
        
        int sz = sres.length();
        int j = 0;
        
        temp = 0;
        while (j < sz) {
            temp = temp * 10;
            temp = temp + sres[j] - '0';
            j++;
        }
        
        return temp;
        
    }
};


/*

216 / 216 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 6.4 MB
Submitted: 0 minutes ago


*/
