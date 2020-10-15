/*
House Robber II

Solution
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact 
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
   Hide Hint #1  
Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.

*/
class Solution {
public:
    
        int __rob(vector<int> &nums, int start, int end)
        {
            int prevTwo = 0, prevOne = 0;
            int max2  = 0;
            
            if (start > end || start < 0) return -1;
            
            
            while (start <= end)
            {
                max2 = max(prevTwo + nums[start], prevOne);
                
                prevTwo = prevOne;
                prevOne = max2;
                
                start++;
            }
            
            return max2;
        }
    
        int rob(vector<int>& nums) {
        
            int n = nums.size();
            
            if (n == 0) return 0;
            if (n == 1) return nums[0];
            if (n == 2) return max(nums[0], nums[1]);
            
            // Following the hint:
            
            return max(__rob(nums, 0, n - 2), __rob(nums, 1, n-1));

            
            
            /*
            74 / 74 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 8 MB
Submitted: 0 minutes ago

            
            */
        }
    
    /*

    int rob(vector<int>& nums) {
        
        
        int n = nums.size();
        
        // We need to follow Dynamic Programming(DP) approach to solve this problem 
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int i;
        vector<int> dp(n, 0);
        
        // Initialize first 2 elements of the array
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); // second will have choice
        
        for (i = 2; i < n - 1; i++)
        {
            dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
        }
        
        //return dp[i-2];
        
        vector<int> dp2(n, 0);
        
        // Initialize first 2 elements of the array
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]); // second will have choice
        
        for (i = 3; i < n; i++)
        {
            dp2[i] = max(dp2[i-1] , nums[i] + dp2[i-2]);
        }
        
        //return dp2[i-1];
        
        return max(dp[i-2], dp2[i-1]);
        
    }
    */
};
