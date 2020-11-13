/*
Permutations II

Solution
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/

class Solution {
public:
    
    inline void swap(vector<int> &nums, int i, int j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    
    // In this backtracking function, we are replacing element in-place
    void permute(vector<int> &nums, int start_index, set<vector<int>> &res)
    {
        if (start_index == nums.size())
        {
            res.insert(nums); //Reached at the base condition, add this to result set
        }
        
        for (int i = start_index; i < nums.size(); i++)
        {
            swap(nums, i, start_index);
            permute(nums, start_index + 1, res);
            swap(nums, i, start_index);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> res;
        
        permute(nums, 0, res);
        
        vector<vector<int>> res2;
    
        // Convert set to Vector of Vectors
        auto iter = res.begin();
        
        while (iter != res.end())
        {
            res2.push_back(*iter);
            iter++;
        }
        
        return res2;
        
        /*
                33 / 33 test cases passed.
        Status: Accepted
        Runtime: 248 ms
        Memory Usage: 9.8 MB
        Submitted: 0 minutes ago

        */
        
    }
};
