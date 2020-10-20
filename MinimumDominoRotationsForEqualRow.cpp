/*
Minimum Domino Rotations For Equal Row

Solution
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= A.length == B.length <= 2 * 104
1 <= A[i], B[i] <= 6


*/


class Solution {
public:
    
    inline int __check(vector<int>& A, vector<int>& B, int target, int keep) 
    {
    
        int asz = A.size(), bsz = B.size();
        // keep represent 0/1 0 - A keep and check can we make A by taking from B
        // 1 - B; keep B and check can we make B by taking from A
        
        int i;
        int swap_count = 0;
        int t = 0;
        for (i = 0; i < asz; i++)
        {
            if (keep == 0)
            {
                if (A[i] != target)
                {
                    if (B[i] == target)
                    {
                        swap_count++;
                    }
                    else
                        return -1; // Not possible to make it
                }
            }
            else
            {
                if (B[i] != target)
                {
                    if (A[i] == target)
                    {
                        swap_count++;
                    }
                    else
                        return -1; // Not possible to make it
                }
            }
        }
        
        return swap_count;
    }
    
        
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        int asz = A.size(), bsz = B.size();
        
        if (asz == 0 || bsz == 0) return 0;
        
        if (asz != bsz) return -1;
        
        
        
         #if 0
        // Eligant code compare to bottom one; adding loop and minimum variables
        // For some reason; this code sees higher runtime compare to bottom
        vector<int> tres(6, 0);
        int i = 0;
        
        for (i = 1; i <= 6; i++)
        {
            int acnt = __check(A, B, i, 0); // 0 -  means keeping A as constant
            int bcnt = __check(A, B, i, 1); // 1 -  means keeping A as constant
            int final_count = 0;
            
            if (acnt == -1 && bcnt == -1)
                 final_count = -1;
            else if (acnt == -1 || bcnt == -1)
                final_count = max(acnt, bcnt);
            else
                final_count = min(acnt, bcnt);

            tres[i-1] = final_count;
            
        }
        
        sort(tres.begin(), tres.end());
        
        if (tres[5] == -1)
            return -1;
        
        //find first non -1
        for (int i = 0; i < 6; i++)
        {
            if (tres[i] != -1) return tres[i];
        }
        
         #endif
        
        //#if 0
        
        // More code ;...... But will work for all cases
        
        // 1
        int one_count1 = __check(A, B, 1, 0);
        int one_count2 = __check(A, B, 1, 1);
        int ones;
        
        if (one_count1 == -1 && one_count2 == -1)
            ones = -1;
        else if (one_count1 == -1 || one_count2 == -1)
            ones = max(one_count1, one_count2);
        else
            ones = min(one_count1, one_count2);
        
        // 2
        int two_count1 = __check(A, B, 2, 0);
        int two_count2 = __check(A, B, 2, 1);
        int twos;
        
        if (two_count1 == -1 && two_count2 == -1)
            twos = -1;
        else if (two_count1 == -1 || two_count2 == -1)
            twos = max(two_count1, two_count2);
        else
            twos = min(two_count1, two_count2);
        
        //3
        int t3_count1 = __check(A, B, 3, 0);
        int t3_count2 = __check(A, B, 3, 1);
        int t3s;
        
        if (t3_count1 == -1 && t3_count2 == -1)
            t3s = -1;
        else if (t3_count1 == -1 || t3_count2 == -1)
            t3s = max(t3_count1, t3_count2);
        else
            t3s = min(t3_count1, t3_count2);
        
        //4
        int f_count1 = __check(A, B, 4, 0);
        int f_count2 = __check(A, B, 4, 1);
        int frs;
        
        if (f_count1 == -1 && f_count2 == -1)
            frs = -1;
        else if (f_count1 == -1 || f_count2 == -1)
            frs = max(f_count1, f_count2);
        else
            frs = min(f_count1, f_count2);
        
        
        //5
        int fv_count1 = __check(A, B, 5, 0);
        int fv_count2 = __check(A, B, 5, 1);
        int fvs;
        
        if (fv_count1 == -1 && fv_count2 == -1)
            fvs = -1;
        else if (fv_count1 == -1 || fv_count2 == -1)
            fvs = max(fv_count1, fv_count2);
        else
            fvs = min(fv_count1, fv_count2);
        
        
        //6
        int s_count1 = __check(A, B, 6, 0);
        int s_count2 = __check(A, B, 6, 1);
        int sxs;
        
        if (s_count1 == -1 && s_count2 == -1)
            sxs = -1;
        else if (s_count1 == -1 || s_count2 == -1)
            sxs = max(s_count1, s_count2);
        else
            sxs = min(s_count1, s_count2);
        
        
        vector<int> res(6, 0);
        res[0] = ones;
        res[1] = twos;
        res[2] = t3s;
        res[3] = frs;
        res[4] = fvs;
        res[5] = sxs;
        
        
        sort(res.begin(), res.end());
        
        if (res[5] == -1)
            return -1;
        
        //find first non -1
        for (int i = 0; i < 6; i++)
        {
            if (res[i] != -1) return res[i];
        }
        
        //#endif
        
        // Should not come here
        
        return -99;
        
        /*
            // BEST part is - You are here! 
                    ---- Your runtime beats 99.17 % of cpp submissions.        
            81 / 81 test cases passed.
                Status: Accepted
                Runtime: 236 ms
                Memory Usage: 111.8 MB
                Submitted: 0 minutes ago
        */
        
        
    }
};
