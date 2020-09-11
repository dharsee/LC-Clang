/*
Maximum Product Subarray

Solution
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        if (n <= 0) return 0;
        
        if (n == 1) return nums[0];
        
        // Better approach, Dynamic programming
        // maintain max_till_now, min_till_now, overall_result
        
        int i;
        int maxp, minp, res;
        
        //Start with first var
        maxp = minp = res = nums[0];
        
        // Loop from second element in the array
        for (i = 1; i < n; i++)
        {
            int maxp_prev = maxp; // This is important to calculate minp
            maxp = max({nums[i]*maxp, nums[i]*minp, nums[i]}); 
            minp = min({nums[i]*maxp_prev, nums[i]*minp, nums[i]});
            
            res = max(res, maxp);
        }
        
        
        // Runtime has improved a lot 
        // for Dynamin progrmming approach, it ws 8 ms whereas bruteforce method is 344 ms.
        // For DP method, runtime complexity would be O(N)
        return res;
        
        
        
        /*
        
        // Brute force approach : which is runtime is O(n^2)
        int maxp = 0;
        int single_max = INT_MIN;
        
        int i, j;
        
        // Runtime O(n^2)
        for (i = 0; i < n; i++)
        {
            if (nums[i] > single_max) single_max = nums[i];
            
            int curr_p = nums[i];
            for (j = i + 1; j < n; j++)
            {
                curr_p *= nums[j];
                if (curr_p > maxp) maxp = curr_p;
            }
            //printf("\nStart from i %d to end product = %d, maxp = %d", i, curr_p, maxp);
            //if (curr_p > maxp) maxp = curr_p;
        }
        
        return max(single_max, max(maxp, nums[n-1]));
        
        */
    }
};


/*

Runtime:

For BruteForce:

187 / 187 test cases passed.
Status: Accepted
Runtime: 344 ms
Memory Usage: 11.8 MB


With DP:

187 / 187 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 11.8 MB

*/
