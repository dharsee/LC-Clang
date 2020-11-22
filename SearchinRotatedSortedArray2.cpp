/*
81. Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

*/

class Solution {
public:
    
    bool __search(vector<int> &nums, int start, int end, int target)
    {
        if (start > end) return false;
        
        // Find middle
        
        int mid = (end - start) / 2 + start;
        
        if (nums[mid] == target)
            return true;
        
        if (nums[mid] <= nums[end])
        {
            bool x = false;
            bool y = false;
            
            if (target >= nums[mid] && target <= nums[end])
            {
                x = __search(nums, mid + 1, end, target);
            }
            else
            {
                y = __search(nums, start, mid - 1, target);
            }
            
            if (x || y) return true;
        }
        
        if (target >= nums[start] && target <= nums[mid])
            return __search(nums, start, mid - 1, target);
        
            return __search(nums, mid + 1, end, target);
    }
    
    
    bool search(vector<int>& nums, int target) {
    
        return __search(nums, 0, nums.size() - 1, target);
        
        /*
        
                Success
        Details 
        Runtime: 12 ms, faster than 43.51% of C++ online submissions for Search in Rotated Sorted Array II.
        Memory Usage: 14.2 MB, less than 72.59% of C++ online submissions for Search in Rotated Sorted Array II.
        */
    }
};
