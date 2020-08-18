/*
Numbers With Same Consecutive Differences

Solution
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9

*/


class Solution {
public:
    void dfs(int root, int N, int K, vector<int> &res)
    {
        // Base case for recursion
        //printf(" .. DFS R:%d N:%d ", root, N);
        if (N == 0)
        {
            res.push_back(root);
            return;
        }
        
        int last_digit = root % 10;
        
        if (last_digit >= K)
        {
            dfs(root * 10 + last_digit - K, N - 1, K, res);
        }
        if (K > 0 && last_digit + K < 10) 
        {
            dfs(root * 10 + last_digit + K, N - 1, K, res);
        }
        
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        
   
        vector<int> r;
        int i = 0;
        
        if (N == 1)
            r.push_back(0);
        
        for (i = 1; i < 10; i++)
        {
            dfs(i, N-1, K, r);
        }
    
        return r;
    }
};
