/*
Find Minimum in Rotated Sorted Array II

Solution
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/



class Solution {
public:
    

    int binsearch(vector<int> &a, int l, int h)
    {
        if (l == h) return a[l];
        
        int mid = l + (h - l)/2;
        
        if (a[mid] > a[h]) return binsearch(a, mid + 1, h);
        
        if (a[mid] < a[h]) return binsearch(a, l, mid);
        
        // if they are equal
        
        return binsearch(a, l, h-1);
            
    }
    
    
    int findMin(vector<int>& nums) {
     
        int n = nums.size();
           
        return binsearch(nums, 0, n - 1);
        
    }
    
    
    #if 0
    /* 
    // Iterative approach 
    */
    int binsearch(vector<int> a)
    {
        int l = 0, h = 0, mid = 0;
        int n = a.size();
        
        h = n - 1;
        
        while (l <= h)
        {
            mid = (h-l)/2 + l;
            
            if (l == h) return a[l];
            
            if (a[mid] < a[h])
            {
                h = mid;
            }
            else if (a[mid] > a[h])
            {
                l = mid+1;
            }
            else // a[mid] == a[h]
            {
                h = h - 1;
            }
        }
       
        return -1;
    }
    
    int findMin(vector<int>& nums) {
     
        int n = nums.size();
        
        //if (n == 0) return -1;
        if (n == 1) return nums[0];
        
        //if (nums[0] < nums[n-1]) return nums[0];
        
        return binsearch(nums);
        
    }
    #endif
    
};
