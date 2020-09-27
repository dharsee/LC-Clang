/*
209. Minimum Size Subarray Sum
Medium

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

*/
class Solution {
public:
    
    // Runtime O(N^2) solution to explore all possible subarrays and see if they matches 
    // Runtime 500 ms, which is not acceptable
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int total = 0;
        int i, j, n = nums.size();
        int curr_total = 0, curr_len = 0;
        
        for (i = 0; i < n; i++)
        {
            total += nums[i];
            if (nums[i] >= s) return 1;
        }
        
        if (total < s) return 0;
        else if (total == s) return n;
        
        for (i = 2; i < n; i++)
        {
            curr_total = 0;
            for (j = 0; j < i; j++)
            {
                curr_total += nums[j];
            }
            
            if (curr_total >= s) return i;
            
            for (; j < n; j++)
            {
                curr_total -= nums[j-i];
                curr_total += nums[j];
                
                if (curr_total >= s) return i;
            }
            
        }
        
        return 0;
        
    }
    
    /*
    Runtime was not good.
    15 / 15 test cases passed.
Status: Accepted
Runtime: 448 ms
Memory Usage: 10.7 MB
Submitted: 4 minutes ago


NOTE: Better solution would be implment two pointer approach or Binary search approach
    
    */
};

