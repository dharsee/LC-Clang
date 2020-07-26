/*
153. Find Minimum in Rotated Sorted Array
Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

class Solution {
public:
    
    // Recursive approach
    int bin_search(vector<int> a, int l, int h)
    {
        int mid = l + (h - l)/2;
        
        if (a[l] < a[mid]) return bin_search(a, mid, h);
        else if (a[mid] < a[h]) return bin_search(a, l, mid);
        else
        {
            if (a[mid] > a[h]) return a[h];
            else if(a[mid] < a[l]) return a[mid];
            else return a[l];
        }
    }
    
    
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        //if (n == 0) return -1;
        if (n == 1) return nums[0];
        
        if (nums[0] < nums[n-1]) return nums[0];
        
        return bin_search(nums, 0, n - 1);
        
        
    }
    
    
    #if 0
    
    // Iterartive approach
    
    int binsearch(vector<int> a)
    {
        int l = 0, h = 0, mid = 0;
        int n = a.size();
        
        h = n - 1;
        
        while (l < h)
        {
            mid = (h-l)/2 + l;
            
            if (a[l] < a[mid])
                l = mid;
            else if (a[mid] < a[h])
                h = mid;
            else
            {
                if (a[mid] > a[h])
                    return a[h];
                else if(a[mid] < a[l])
                    return a[mid];
                else
                    return a[l];
            }
        }
       
        return -1;
    }
    
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        //if (n == 0) return -1;
        if (n == 1) return nums[0];
        
        if (nums[0] < nums[n-1]) return nums[0];
        
        return binsearch(nums);
        
        
    }
    #endif
};
