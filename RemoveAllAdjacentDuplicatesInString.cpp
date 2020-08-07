/*
1047. Remove All Adjacent Duplicates In String

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.

*/

class Solution {
public:
    string removeDuplicates(string S) {
        
        int n = S.length();
        if (n == 0) return "";
        if (n == 1) return S;
        
        int i, j, k;
        
        j = 0;
        i = 1;

        while (i < n)
        {
            if (S[j] != S[i])
            {
                if (j != i - 1)
                {
                    if (j < 0) j = -1;
                    
                    S[++j] = S[i];
                }
                else
                    j++;
            }
            else
            {
                // go back one index of j
                if (j <= 0)
                {
                    if (i + 1 < n)
                    {
                        if (j < 0) j = 0;
                        S[j] = S[++i];
                    }
                    else
                    {
                        // There are no characters left in the input string
                        --j;
                        break;
                    }   
                }
                else
                {
                    --j;
                }
            }
            
            i++;
            //cout << "i ="  << i << " j =" << j << " s=[" << S << "]" <<endl;
        }
        
        //cout << "s=["<<S << "]";
        
        if (j < 0) return "";
        
        //cout << " Post s=["<<S << "]";
        //printf(" i = %d j = %d ", i, j);
        
        S.resize(j+1);
        
        return S;
    }
};


/*

Success
Details 
Runtime: 36 ms, faster than 99.69% of C++ online submissions for Remove All Adjacent Duplicates In String.
Memory Usage: 9.1 MB, less than 99.13% of C++ online submissions for Remove All Adjacent Duplicates In String.
Next challenges:

*/
