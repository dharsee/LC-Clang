/*


628. Maximum Product of Three Numbers

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000


*/


class Solution {
public:
     int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int left = 0, right = n - 1;
        
        return max(nums[0] * nums[1] * nums[right], 
                   nums[right] * nums[right-1] * nums[right-2]); 
        
    }
    
    /* This method would not work for mixed numbers
       particularly for these type of examples [-100,-2,-3,1]
       */
    int maximumProduct2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int left = 0, right = n - 1;
        
        int f = INT_MAX, s = INT_MAX, t = INT_MAX;
        
        int count = 0;
        
        // only -ve case
        
        if (nums[right] < 0) {
            f = nums[left++];
            s = nums[left++];
            t = nums[left++];
            return (f * s* t); 
        }
        
        // only positive case
        if (nums[left] > 0) {
            f = nums[right--];
            s = nums[right--];
            t = nums[right--];
            return (f * s* t); 
        }
        
        while (left <= right && count < 3) {
            if (nums[left] < 0) {
                if (-nums[left] > nums[right]) {
                    if (f == INT_MAX) f = nums[left];
                    else if (s == INT_MAX) s = nums[left];
                    else if (t == INT_MAX) t = -nums[left];
                    left++;
                } else {
                    if (f == INT_MAX) f = nums[right];
                    else if (s == INT_MAX) s = nums[right];
                    else if (t == INT_MAX) t = nums[right];
                    
                    right--;
                }
            } else {
                if (f == INT_MAX) f = nums[right];
                else if (s == INT_MAX) s = nums[right];
                else if (t == INT_MAX) t = nums[right];
                    
                right--;
            }
            
            count++;
        }
        
        /*
        if (f == INT_MAX || s == INT_MAX || t == INT_MAX) {
            cout << endl << "Something is not correct...[" << f << ", " << s << ", " << t << "]";
        }
        */
        
        return (f * s* t); 
        
    }
};


/*
Success
Details 
Runtime: 54 ms, faster than 12.66% of C++ online submissions for Maximum Product of Three Numbers.
Memory Usage: 27.7 MB, less than 35.06% of C++ online submissions for Maximum Product of Three Numbers.

*/
