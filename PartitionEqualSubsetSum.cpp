/*
416. Partition Equal Subset Sum

Given a non-empty array nums containing only positive integers, find if the array can be 
partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/

class Solution {
public:

    
    
    // This Solution is exceeding time limit
    
    bool helper(vector<int> &nums, int n, int subSetSum,
               vector<vector<optional<bool>>> &dp)
    {
        // BASE CASE
        if (subSetSum == 0) return true;
        
        if (n == 0 || subSetSum < 0) return false;
        
        // Use the DP 
        
        if (dp[n][subSetSum] != nullopt)
            return (dp[n][subSetSum] == true);
        
        
        bool res = helper(nums, n - 1, subSetSum - nums[n-1], dp) || helper(nums, n - 1, subSetSum, dp);

        dp[n][subSetSum] = res;
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        
        // Find Sum of input array
        
        int i, n = nums.size();
        
        for (i = 0; i < n; i++)
            totalSum += nums[i];
        
        // Early check, if totalSum is ODD then it cannot be possible to partition
        if (totalSum & 0x1) return false;
        
        int subSetSum = totalSum / 2;
        
        
        // Introducing memoization arra for DP 
        vector<vector<optional<bool>>> dp(n + 1, vector<optional<bool>>(subSetSum + 1, nullopt));
        
        return helper(nums, n - 1, subSetSum, dp);
        
        
        /*
                    Success
            Details 
            Runtime: 256 ms, faster than 45.18% of C++ online submissions for Partition Equal Subset Sum.
            Memory Usage: 44.1 MB, less than 16.50% of C++ online submissions for Partition Equal Subset Sum.
        
        */
        
    }
    
    
#if 0
    // This Solution is exceeding time limit
    
    bool helper(vector<int> &nums, int n, int subSetSum)
    {
        // BASE CASE
        if (subSetSum == 0) return true;
        
        if (n == 0 || subSetSum < 0) return false;
        
        bool res = helper(nums, n - 1, subSetSum - nums[n-1]) || helper(nums, n - 1, subSetSum);

        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        
        // Find Sum of input array
        
        int i, n = nums.size();
        
        for (i = 0; i < n; i++)
            totalSum += nums[i];
        
        // Early check, if totalSum is ODD then it cannot be possible to partition
        if (totalSum & 0x1) return false;
        
        int subSetSum = totalSum / 2;
        
        return helper(nums, n - 1, subSetSum);
        
    }
    
#endif
};
