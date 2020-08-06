/*

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        
        if (n <= 1) return res;
        
        int i, k;
        
        //Could you do it without extra space and in O(n) runtime?
        // This solution is O(1) space and O9n) runtime
        // In this solution input arrays would be modified
        // we can flip all the negative signs if wanted 
        // but what is your input array is constant
        
        for (i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1; // Since input range is from 1 but array index is from 0
            if (nums[index] < 0)
            {
                // Already seen: we have seen this and marked as negative
                // so add this value to the result array
                res.push_back(abs(nums[i]));
            }
            else
            {
                nums[index] = -nums[index]; // Change its sign to know that we have seen 
            }
        }
        
        return res;
        
    }
};
