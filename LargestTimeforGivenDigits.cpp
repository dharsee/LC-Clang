/*
Largest Time for Given Digits

Solution
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9

*/

class Solution {
 
    void print_v(vector<int> &A)
    {
        int i = 0;
        
        printf("\n");
        while (i < A.size())
            printf(" %2d", A[i++]);
    }
    
    
    
    bool fill(vector<int> &A, vector<int> &allowed_digits, string &res)
    {
        //print_v(allowed_digits);
        
        int i, j, k;
        int n = A.size();
        
        for (i = 0; i < allowed_digits.size(); i++)
        {
            for (j = 0; j < n; j++)
            {
                if (A[j] == allowed_digits[i])
                {
                    res += to_string(A[j]);
                    A[j] = -9;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
    
public:
    string largestTimeFromDigits(vector<int>& A) {
        
        string res;
        
        int n = A.size();
        vector<int> temp = A;
        
        if (n < 4) return res;
        bool pass = true;
        bool ret = false;
        
        for (int i = 2; i >= 0; i--) // This loop is only for cases like [2,0,6,6]
        {

            pass = true;
            res = "";
            // Hours
            A = temp;
            
            vector<int> allowed_digits;
            int j = i;
            while (j >= 0)
                allowed_digits.push_back(j--);
            
            ret = fill(A, allowed_digits, res);
            if (!ret) pass = false;

            if (res[0] == '2')
                allowed_digits = {3,2,1,0};
            else
                allowed_digits = {9,8,7,6,5,4,3,2,1,0};
            
            ret = fill(A, allowed_digits, res);
            if (!ret) pass = false;
            
            res += ":";
            
            // Minutes
            allowed_digits = {5,4,3,2,1,0};
            ret = fill(A, allowed_digits, res);
            if (!ret) pass = false;
            
            allowed_digits = {9,8,7,6,5,4,3,2,1,0};
            ret = fill(A, allowed_digits, res);
            if (!ret) pass = false;
            
            if (pass) break;
        }
        
        if (!pass) return "";
        return res;
        
    }
};
