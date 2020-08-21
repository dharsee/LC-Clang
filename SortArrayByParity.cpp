/*
Sort Array By Parity

Solution
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000


*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int n = A.size();
        if (n <= 1) return A;
        
        int i, j;
        
        
        i = 0;
        j = n - 1;
        while (i <= j)
        {
            while (i <= j && (A[j] & 0x1)) --j; // ODD no need to swap
            while (i <= j && (A[i] & 0x1) == 0) ++i; // EVEN no need to swap
            
            
            if (i > j) break; // Otherwise indices might go out of bound
            // swap i anf j
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            
            i++;
            --j;
        }
        
        return A;
        
    }
};

