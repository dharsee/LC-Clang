/*

Search for a Range

Solution
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9

*/

class Solution {
public:
    
    
    //return the index of target, -1 if doest not exists
    int bin_search(vector<int> nums, int l, int h, int target)
    {
        int n = nums.size();
        int mid = 0;
        
        while (l <= h)
        {
            mid = (h - l) / 2 + l;
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) h = mid - 1;
            else l = mid + 1;
        }
        
        // Does not exists 
        return -1;
    }
    
    // taking advantage of sortedness, apply binary search method to find the existance
    // if exists then move both direction to find its end points
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<int> res(2, -1);
        if (n == 0) return res;
        if (n == 1)
        {
            if (nums[0] == target)
                return (vector<int>{0,0});
            else
                return res;
        }
        
        if (nums[0] == target && nums[n-1] == target)
        {
            res[0] = 0;
            res[1] = n - 1;
            return res;
        }
        
        int i = 0;
        int j = n - 1;
        
        
        // First see if target is exists in the list or not
        int indx = bin_search(nums, 0, n - 1, target);
        if (indx == -1)
        {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        
        // Element is present in the array
        // Look for best case effort
        int start = -1, end = - 1;
        if (nums[0] == target)
            start = 0;
        if (nums[n-1] == target)
            end = n - 1;
        
        if (start != 0)
        {
            // try to find its start index
            int prev = -1;
            start = indx;
            while (start != prev)
            {
                prev = start;
                start = bin_search(nums, 0, start, target);
                
            }
            int f = 0;
            while (start >= 0)
            {
                
                if (nums[start] == target) { --start; f = 1;}
                else break;
            }
            
            if (f) start++;
            // Now we know start
        }
        
        if (end != n-1)
        {
            // try to find its end index
            int prev = -1;
            end = indx;
            while (end != prev)
            {
                //printf("\n End == prev = %d end = %d ", prev, end);
                prev = end;
                end = bin_search(nums, end, n-1, target);
                //printf("  ... New End : %d ", end);
                
            }
            
            int f = 0;
            while (end < n)
            {
                if (nums[end] == target) { end++; f = 1;}
                else break;
            }
            
            if (f) end--;
            
            // Now we know end
        }
        
        res[0] = start;
        res[1] = end;
        
        return res;
        
    }
    
    // Naive approach, not taking advantage of sortedness
    vector<int> searchRange_2(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<int> res(2, -1);
        if (n == 0) return res;
        if (n == 1)
        {
            if (nums[0] == target)
                return (vector<int>{0,0});
            else
                return res;
        }
        
        if (nums[0] == target && nums[n-1] == target)
        {
            res[0] = 0;
            res[1] = n - 1;
            return res;
        }
        
        int i = 0;
        int j = n - 1;
        
        bool imove = true, jmove = true;
        
        while (i <= j )
        {    
            if (nums[i] != target) i++;
            else imove = false;
                
            if (nums[j] != target) --j;
            else jmove = false;
            
            if (!imove && !jmove) break;
        }
        
        if (imove && jmove)
        {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        
        res[0] = i;
        res[1] = j;
        
        return res;
        
    }
};
