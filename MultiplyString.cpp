/*
43. Multiply Strings
Medium

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/
class Solution {
public:
    
    void dump_vect(vector<vector<int>> &v)
    {
        int i, j, r = v.size();
        
        printf("\n Result Vector:\n");
        for (i = 0; i < r; i++)
        {
            int n = v[i].size();
            
            for (j = 0; j < n; j++)
            {
                printf("%3d ", v[i][j]);
            }
            printf("\n");
        }
        
    }
    
    string multiply(string num1, string num2) {
     
        int n1 = num1.length(), n2 = num2.length();
        string sres = "";
        if (n1 == 0 && n2 == 0) return "0";
        
        if (n1 && num1[0] == '0') return "0";
        
        if (n2 && num2[0] == '0') return "0";
        
        
        vector<vector<int>> res;
        vector<int> curr;
        
        int i, j, k, m;
        
        string ts1, ts2;
        if (n1 > n2)
        {
            ts1 = num1;
            ts2 = num2;
        }
        else
        {
            ts1 = num2;
            ts2 = num1;
            
            n1 = ts1.length();
            n2 = ts2.length();
        }
        
        
        k = 0;
        int max_len = 0;
        
        for (j = n2 - 1; j >= 0; j--)
        {
            int carry = 0;
            int jnum = ts2[j] - '0';
            vector<int> curr;
            for (i = n1 - 1; i >= 0; --i)
            {
                int inum = 0, r = 0;
                
                inum = ts1[i] - '0';
                r = jnum * inum + carry;
                
                carry = r / 10;
                if (r > 9)  r = r % 10;
                
                if (i == n1 -1) // first time
                {
                    for (m = 0; m < k; m++)
                        curr.push_back(0);
                }
                curr.push_back(r);
            }
            if (carry) curr.push_back(carry);
            
            if (curr.size() > max_len) max_len = curr.size();
            
            res.push_back(curr);
            k++;
        }
        
        //dump_vect(res);
        
        // Buils Sum vector
        vector<int> temp;
        
        //printf("\n Res.size () = %d max_len = %d ", res.size(), max_len);
        int carry = 0, s = 0;
        for (i = 0; i < max_len; i++) // column
        {
            s = 0;
            for (j = 0; j < res.size(); j++) // Rows
            {
                if (res[j].size() > i)
                    s += res[j][i];
            }
            
            s += carry;
            carry = s / 10;
            if (s > 9) s = s % 10;
            
            temp.push_back(s);
        }
        
        if (carry) temp.push_back(carry);
        
        /*
        // Dump res vect (1D)
        printf("\n 1D vector :\n");
        for (i = 0; i < temp.size(); i++)
            printf(" %2d ", temp[i]);
        */
        
        // Build res string reverse of temp 
        
        for (i = temp.size() - 1; i >= 0; i--)
        {
            sres += to_string(temp[i]);
        }
        
        
        return sres;
        
    }
};
