/*
K-diff Pairs in an Array

Solution
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
a <= b
b - a == k
 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Example 4:

Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2
Example 5:

Input: nums = [-1,-2,-3], k = 1
Output: 2
 

Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107


*/


class Solution {
public:
    
    int bin_search(vector<int>& nums, int k, int src_index)
    {
        int l, h, mid;
        
        l = 0;
        h = nums.size() - 1;
        
        while(l <= h)
        {
            mid = (h - l) / 2 + l;
            if (nums[mid] == k && mid != src_index) return nums[mid];
            else if (nums[mid] > k) h = mid - 1;
            else l = mid + 1;
        }
        
        // Indicates does not exist.
        return INT_MAX;
    }
    
    int findPairs(vector<int>& nums, int k) {
        
        set<pair<int, int>> res_set; // This is also important to maintain unique result set
        int i, n = nums.size();
        
        if (n <= 1) return 0;
        
        // SORT input array
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < n; i++)
        {
            
            int ret = bin_search(nums, k + nums[i], i); // This part pays importantn role
            // As per contraints, b - a == k (means b = k + a) and i != j, so we dont want b which is not at the same index
            if (ret != INT_MAX)
            {
                res_set.insert({nums[i], ret});
            }
        }
        
        return res_set.size();
        
        
        
        /*
        
        59 / 59 test cases passed.
Status: Accepted
Runtime: 60 ms
Memory Usage: 13.5 MB
Submitted: 0 minutes ago

        
        */
    }
};
