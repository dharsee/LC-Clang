/*
Max Consecutive Ones

Solution
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.


Hide Hint #1  

You need to think about two things as far as any window is concerned. 
One is the starting point for the window. 
How do you detect that a new window of 1s has started? 
The next part is detecting the ending point for this window. 
How do you detect the ending point for an existing window? 
If you figure these two things out, you will be able to detect the windows of consecutive ones. 
All that remains afterward is to find the longest such window and return the size.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int i, j, curr_len = 0, max_len = 0;
        
        if (n == 1) {
            if (nums[0] == 1) return 1;
            else return 0;
        }
        
        for (i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (curr_len > max_len)
                    max_len = curr_len;
                curr_len = 0;
            } else {
                curr_len++;
            }
        }
        
        if (curr_len > max_len)
            max_len = curr_len;
                
        return max_len;
        
    }
};

/*


42 / 42 test cases passed.
Status: Accepted
Runtime: 44 ms
Memory Usage: 36.3 MB
Submitted: 0 minutes ago

*/
