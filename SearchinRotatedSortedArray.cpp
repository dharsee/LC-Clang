/*
Search in Rotated Sorted Array

Solution
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if (n == 0) return -1;
        
        int l = 0, h = n - 1, mid = 0;
        
        while (l <= h)
        {
            mid = (h - l)/2 + l;
            //printf("\n %2d %2d %2d -> %2d", l, mid, h, target);
            if (nums[mid] == target) 
                return mid;
            else if (nums[l] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[l]) h = mid - 1;
                else l = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[h]) l = mid + 1;
                else h = mid - 1;
            }
        }
        
        return -1;
    }
};
