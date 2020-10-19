/*
Best Time to Buy and Sell Stock IV

Solution
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

0 <= k <= 109
0 <= prices.length <= 104
0 <= prices[i] <= 1000

*/


/*

// Recurion solution : Working but exceeding run time limit due to duplicate 
// recursive call with the same input parameter/ arguments 

// Solution wold be to follow Dynamic Prograaming approach

class Solution {
public:
    int __maxProfit(int k, vector<int> &p, int index, int ntx, int buy)
    {
        int n = p.size();
        
        // BASE condition for recursion
        if (index >= n ||  ntx >= k) return 0;
        
        
        if (buy == 1)
        {
            return max(-p[index] + __maxProfit(k, p, index + 1, ntx, 0), 
                       __maxProfit(k, p, index + 1, ntx, 1));
        }
        else
        {
            return max(p[index] + __maxProfit(k, p, index + 1, ntx + 1, 1), 
                       __maxProfit(k, p, index + 1, ntx, 0));
        }
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        return __maxProfit(k, prices, 0, 0, 1);
        
    }
};

*/


#if 0



// Using DP ; Good but fails when K increases and k >= arrays.size() / 2

//Runtime Error Message:
//=================================================================
//==29==ERROR: AddressSanitizer: allocator is out of memory trying to allocate 0x59682f018 bytes
//    #10 0x7fcb3f8b70b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
//==29==HINT: if you don't care about these errors you may set allocator_may_return_null=1
//==29==ABORTING
//Last executed input:
//1000000000
    

class Solution {
    
    
    //int dp[][2][2];
    
public:
    int __maxProfit(int k, vector<int> &p, int index, int ntx, int buy, vector<vector<vector<int>>> &dp)
    {
        int n = p.size();
        
        // BASE condition for recursion
        if (index >= n ||  ntx >= k) return 0;
        
        // If it is already computed then use it
        if (dp[index][ntx][buy] > 0) return dp[index][ntx][buy];
        
        if (buy == 1)
        {
            return dp[index][ntx][buy] = max(-p[index] + __maxProfit(k, p, index + 1, ntx, 0, dp), 
                       __maxProfit(k, p, index + 1, ntx, 1, dp));
        }
        else
        {
            return dp[index][ntx][buy] = max(p[index] + __maxProfit(k, p, index + 1, ntx + 1, 1, dp), 
                       __maxProfit(k, p, index + 1, ntx, 0, dp));
        }
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
    
        int n = prices.size();
        
        // 3D vector with all 0s
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        
        return __maxProfit(k, prices, 0, 0, 1, dp);
        
    }
};


#endif


// Handling case where k >= array.size() / 2;


class Solution {
    
public:
    int __maxProfit(int k, vector<int> &p, int index, int ntx, int buy, vector<vector<vector<int>>> &dp)
    {
        int n = p.size();
        
        // BASE condition for recursion
        if (index >= n ||  ntx >= k) return 0;
        
        // If it is already computed then use it
        if (dp[index][ntx][buy] > 0) return dp[index][ntx][buy];
        
        if (buy == 1)
        {
            return dp[index][ntx][buy] = max(-p[index] + __maxProfit(k, p, index + 1, ntx, 0, dp), 
                       __maxProfit(k, p, index + 1, ntx, 1, dp));
        }
        else
        {
            return dp[index][ntx][buy] = max(p[index] + __maxProfit(k, p, index + 1, ntx + 1, 1, dp), 
                       __maxProfit(k, p, index + 1, ntx, 0, dp));
        }
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
    
        int n = prices.size();
        
        
        // Special case to handle larger k value
        if (k >= n / 2)
        {
            int i = 0;
            int maxProf = 0;
            
            for (i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    maxProf += prices[i] - prices[i - 1];
                }
            }
            
            return maxProf;    
        }
        
        
        // 3D vector with all 0s
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        
        return __maxProfit(k, prices, 0, 0, 1, dp);
        
    }
    
    
    /*
    212 / 212 test cases passed.
Status: Accepted
Runtime: 68 ms
Memory Usage: 22.7 MB
Submitted: 0 minutes ago
    
    */
};
