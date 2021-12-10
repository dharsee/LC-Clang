/*
790. Domino and Tromino Tiling
Medium  - 889  - 410 -- Add to List

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000


*/

class Solution {
public:
    int MOD = 1000000007; // As per given in the description
        
        unordered_map<int, long> f_cache, p_cache;
        
        long p(int n) {
            // First check the answer in the cache if already computed for this combination
            if (p_cache.find(n) != p_cache.end()) {
                return p_cache[n];
            }
            
            // This is the first time we see this combination, so compute and save
            long val = 0;
            
            if (n == 2) val = 1;
            else {
                val = (p(n - 1) + f(n - 2)) % MOD;
            }
            
            // Save  it in the case to get advantage later
            p_cache[n] = val;
            return val;
        }
        
        long f(int n) {
            
            if (f_cache.find(n) != f_cache.end())
                return f_cache[n];
            
            long val = 0;
            
            if (n == 1) val = 1;
            else if (n == 2) val = 2;
            else {
                val = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD;
            }
            
            f_cache[n] = val;
            return val;
        }
        

    int numTilings(int n) {
        // followed -Solution- in from the leetcode
        // This is purely a dynamic programming model with recursion
        
    return (int)f(n);                 
        
        
    }
};




/*

Success
Details 
Runtime: 8 ms, faster than 17.51% of C++ online submissions for Domino and Tromino Tiling.
Memory Usage: 8.9 MB, less than 9.35% of C++ online submissions for Domino and Tromino Tiling.
*/
