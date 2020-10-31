/*
Number of Longest Increasing Subsequence

Solution
Given an integer array nums, return the number of longest increasing subsequences.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 

Constraints:

0 <= nums.length <= 2000
-106 <= nums[i] <= 106

*/


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        // Following listed answer
        
        int n = nums.size();
        if (n <= 1) return n;
        
        // Maintain two arrays of same size as nums to track 
        // count and length of that sequence until that index
        
        vector<int> count(n, 1); // initialized to 1
        vector<int> length(n, 0);
        
        int i, j, longest = 0;
        
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (length[j] >= length[i])
                    {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if (length[j] + 1 == length[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            
            longest = max(longest, length[i]);
            
        }
        
        /*
        // Find the longest
        int longest = 0;
        for (i = 0; i < n; i++)
        {
            longest = max(longest, length[i]);
        }
        */
        // Now count longest
        
        int res = 0;
        for (i = 0; i < n; i++)
        {
            res += (length[i] == longest) ? count[i] : 0;
        }
        
        return res;
        /*
                        225 / 225 test cases passed.
                Status: Accepted
                Runtime: 116 ms
                Memory Usage: 13.6 MB
                Submitted: 0 minutes ago

        
        */
    }
};
