/*
Binary search on sorted array

*/
class Solution {
public:
    
    
    // Approach : Recusrsive method of binary search over sorted array
    int bin_search(vector<int>& nums, int l, int h, int target)
    {
        if (l > h) return -1;
        
        int mid = (h-l)/2 + l;
        
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return bin_search(nums, l, mid - 1, target);
        else return bin_search(nums, mid + 1, h, target);
    }
    
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if (n == 0) return -1;
    
        return bin_search(nums, 0, n - 1, target);
    }
    
    
    /*
    // Approach :  iterating 
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if (n == 0) return -1;
        int l, h, m = 0;
        
        l = 0;
        h = n - 1;
        
        
        while(l <= h)
        {
            m = (h-l)/2 + l;
            
            if (nums[m] == target) return m;
            else if (nums[m] > target) h = m - 1;
            else l = m + 1;
                                        
        }
        
        return -1;
        
    } */
};
