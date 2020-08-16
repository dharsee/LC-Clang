/*
Best Time to Buy and Sell Stock III

Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // Solve it by traversing left - right for trasaction 1
        // right - left for transaction 2
        // then get the max of sum of both profits
        
        int n = prices.size();
        if (n < 2) return 0;
        
        
        int p1 = prices[0], p2 = prices[n-1];
        
        vector<int> profitL(n, 0), profitR(n, 0);
        
        int i;
        
        for(i = 1; i < n; i++)
        {
            // Left - Right 
            profitL[i] = max(profitL[i-1], prices[i] - p1);
            p1 = min(p1, prices[i]);
            
            // Right to left
            int k = n-i-1;
            profitR[k] = max(profitR[k], p2 - prices[k]);
            p2 = max(p2, prices[k]);
        }
        
        // Now find the max profit of two transactions
        
        int total_profit = 0;
        
        for(i = 0; i < n; i++)
        {
            total_profit = max(total_profit, profitL[i] + profitR[i]);
        }
        
        return total_profit;
        
    }
};
