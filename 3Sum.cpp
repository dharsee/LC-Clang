/*

15. 3Sum
Medium

13804

1327

Add to List

Share
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/


class Solution {
public:
    
    void printV(vector<int> &nums){
        cout << endl << "Sorted Input : [";
        auto iter = nums.begin();
        while (iter != nums.end()) {
            cout << *iter << ",";
            iter++;
        }
        cout << "]";
    }
    // Binary search will return index of the found target element if found
    // otherwise it returns -1;
    int bin_search(vector<int>& nums, int l, int h, int target, int debug) {
        int mid = 0;
        
        while (l <= h) {
            mid = ((h - l)/2) + l;
            
            if (debug) {
                cout << endl << "Low = " << l << " Mid = " << mid << " High = " << h;
            }
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else 
                h = mid - 1;
        }
        
        return -1;
        
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> res;
        
        if (n < 3) return res;
        else if (n == 3) {
            if (nums[0] + nums[1] + nums[2] == 0) {
                res.push_back(nums);
                return res;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        // printV(nums);
        
        int i, j, k;
        
        
        
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                
                while(j + 1 < n && nums[j] == nums[j+1]) j++;
                
                int target = -(nums[i] + nums[j]);
                int d = 0;
                /*
                if (i == 1 && j == 13) {
                    cout << endl << "i = " << i << " j = " << j << " Target = " << target;
                    d = 1;
                }
                */
                int k = bin_search(nums, 0, n-1, target, d);
                // if (i == 1 && j == 13) cout << " k = " << k;
                if (k == -1) { // Not found
                    continue; 
                } else if(k == i) {
                    // Look for left and right indices as long as you dont hit with j
                    if (i > 0) {
                        if (i-1 != j && nums[i-1] == target) {
                            res.push_back({nums[i], nums[j], nums[i-1]});
                        } else if (i + 1 < n -1 && i + 1 != j && nums[i+1] == target) {
                            res.push_back({nums[i], nums[j], nums[i+1]});
                        }
                    }    
                } else if(k == j) {
                    // Look for left and right indices as long as you dont hit with j
                    if (j > 0) {
                        if (j-1 != i && nums[j-1] == target) {
                            res.push_back({nums[i], nums[j], nums[j-1]});
                        } else if (j + 1 < n - 1 && j + 1 != i && nums[j+1] == target) {
                            res.push_back({nums[i], nums[j], nums[j+1]});
                        }
                    }    
                } else {
                    // Found triplet, just add it to the result set
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        
        // Sort out vectors items
        n = res.size();
        for (i = 0; i < n; i++) {
            sort(res[i].begin(), res[i].end());
        }
        
        // Filter out duplicates.
        set <vector<int>> s;
        
        n = res.size();
        for (i = 0; i < n; i++) {
            s.insert(res[i]);
        }
        
        // conert back to vector<format>
        vector<vector<int>> r;
        
        auto iter = s.begin();
        while (iter != s.end()) {
            r.push_back(*iter);
            iter++;
        }
       
        return r;
        
        
    }
};


/*
Success
Details 
Runtime: 592 ms, faster than 15.83% of C++ online submissions for 3Sum.
Memory Usage: 44.5 MB, less than 12.89% of C++ online submissions for 3Sum.

*/
