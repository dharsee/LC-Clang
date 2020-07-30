/*
Best Time to Buy and Sell Stock with Cooldown

Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // There will be at most 3 states each transaction may stay in any time
        // A - Beginning or Holding
        // B - When you buy then enter to this state
        // C - When you sell stock you would enter here
        
        int i, j, k;
        int A, B, C;
        
        
        if (prices.size() <= 1) return 0;
        
        // Initial values
        A = 0, B = -prices[0], C = 0;
        
        for (i = 1; i < prices.size(); i++)
        {
            int temp = A;
            A = max(A, C);
            C = B + prices[i];
            B = max(B, temp - prices[i]);
        }
        
        return max(A, C);
    }
};
