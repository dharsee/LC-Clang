/*

Check If All 1's Are at Least Length K Places Away

Solution
Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

 

Example 1:



Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:



Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
Example 3:

Input: nums = [1,1,1,1,1], k = 0
Output: true
Example 4:

Input: nums = [0,1,0,1], k = 1
Output: true
 

Constraints:

1 <= nums.length <= 105
0 <= k <= nums.length
nums[i] is 0 or 1

*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        
        // Looking for O(n) runtime algorithm at first attempt and see if that works for all cases
        int last = 0;
        int i, j;
        
        // find first one here
        i = 0;
        int n = nums.size();
        
        for (i = 0; i < n; i++)
        {
            if (nums[i]) {
                last = i;
                i++;
                break;
            }
        }
        
        // Corner case
        if (i == n)
        {
            if (k < n) return true;
            else return false;
        }
        
        // printf("\n Here ... \n");
        // Now continue scanning nums
        while (i < n)
        {
            if (nums[i]) {
                if (i - last < k + 1) {
                    // printf("\n i = %d last = %d and k = %d", i, last, k);
                    return false;
                }
                last = i;
            }
            i++;
        }
        
        return true;
    }
};
