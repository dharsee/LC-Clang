/*
Combination Sum III

Solution
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

The solution set must not contain duplicate combinations.
 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Example 3:

Input: k = 4, n = 1
Output: []
Example 4:

Input: k = 3, n = 2
Output: []
Example 5:

Input: k = 9, n = 45
Output: [[1,2,3,4,5,6,7,8,9]]
 

Constraints:

2 <= k <= 9
1 <= n <= 60

*/


class Solution {
public:
    
    // At max 9 * (9+1) / 2  = 45 combinations. since possible values willbe 1 to 9 (inclusive)
    // start filling at first position with 1 and then reduce target by 1 ,,, keep exploring 
    // when you see the size of the array is k then check remaining n
    // if they meet condition then add this combination to result.
    // keep exploring.....
    void explore(int start, int n, int k, vector<int> curr_comb, vector<vector<int>> &res)
    {
        //printf("\n Start : %d n = %d, k = %d currsz = %d", start, n, k, curr_comb.size());
        if (curr_comb.size() == k)
        {
            if (n == 0)
                res.push_back(curr_comb);
            
            return;
        }
        
        if (n < 0)
        {
            return;
        }
        
        int i;
        for (i = start; i <= 9; i++)
        {
            curr_comb.push_back(i);
            explore(i + 1, n - i, k, curr_comb, res);
            
            // Take of last inserted and try again
            curr_comb.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> empty;
        vector<vector<int>> res;
        
        explore(1, n, k, empty, res);
        
        return res;
        
    }
};
