/*

377. Combination Sum IV
Medium

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
 

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

*/



class Solution {
public:
    
    /* This is recusrive solution and exceeding timelimit */
    void generate(vector<int>& nums, int target, int &count)
    {
        if (target == 0)
        {
            count++;
            return;
        }
        
        if (target < 0) return;
        
        int i, n = nums.size();
        for (i = 0; i < n; i++)
        {
            generate(nums, target - nums[i], count);
        }
        
    }
    
    int dp_method(vector<int> &nums, int target)
    {
        // Lets create a dp array with size of target+1
        
        vector<int> dp(target + 1, 0);
        
        int i, j, k, n = nums.size();
        
        dp[0] = 1;
        for (i = 1; i <= target; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i - nums[j] >= 0)
                {
                    if (INT_MAX - dp[i] > dp[i-nums[j]]) // TO Avoid integer overflow
                        dp[i] = dp[i] + dp[i-nums[j]];
                }
            }
        }
        
        /*
        // Dump dp array
        for (i = 0; i <= target; i++)
            printf(" %d ", dp[i]);
        */
        
        //printf()
        return dp[target];
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        /* 
        // Recursive method which is exceeding timelimit 
        int count = 0;
        
        generate(nums, target, count);
        
        return count;
        */
        
        // Lets try with Dynamic programming
        
        return dp_method(nums, target);
            
    }

/*
Runtime with Dynamic programming methpd.

Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum IV.
Memory Usage: 7 MB, less than 53.20% of C++ online submissions for


};

