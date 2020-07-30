/*
349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

*/

class Solution {
public:
    
    vector<int> samearrays(vector<int>& nums)
    {
        set<int> res;
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) res.insert(nums[i]);
            
        vector<int> r;
        auto iter = res.begin();
        while (iter != res.end())
        {
            r.push_back(*iter);
            iter++;
        }
        return r;    
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        
        if (nums1 == nums2) return samearrays(nums1);
            
        vector<int> res;
        
        // Sort both input arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // Now walk through both array and see 
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0, k = 0;
        
        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
            {
                if (k == 0)
                {
                    res.push_back(nums1[i]);
                    k++;
                }
                else
                {
                    if (res[k-1] != nums1[i]) 
                    {
                        res.push_back(nums1[i]);
                        k++;
                    }
                }
                
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
                j++;
        }
        
        
        return res;
        
    }
};
