/*
219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false


*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
        // Build hash map 
        // val (key) ----> index (val)
        
        unordered_map<int, int> hmap;
        
        int i, n = nums.size();
        
        if (n <= 1) return false;
        
        for (i = 0; i < n; i++)
        {
            if (hmap.find(nums[i]) != hmap.end())
            {
                // Already seen element, duplicate 
                // Now check its index differene and compare with k
                // if diff is less than k return true; else continue
                
                if (i - hmap[nums[i]] <= k) return true;
                else hmap[nums[i]] = i; // keep new index of this element
                    
            }
            else
            {
                // first time seen, add it to the hmap
                hmap[nums[i]] = i;
            }
        }
        
        return false;
    }
};
