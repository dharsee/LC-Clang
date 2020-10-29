/*

Summary Ranges

Solution
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
Example 3:

Input: nums = []
Output: []
Example 4:

Input: nums = [-1]
Output: ["-1"]
Example 5:

Input: nums = [0]
Output: ["0"]
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.



*/



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> res;
        if (n == 0) return res;
        
        if (n == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        
        int i;
        int start_index = 0;
        for (i = 1; i < n; i++)
        {
            if (nums[i - 1] == nums[i] - 1) // two are consecutive
                continue;
            else
            {
                if (start_index + 1 == i)
                {
                    // Single element case
                    res.push_back(to_string(nums[start_index]));
                }
                else
                {
                    // multi element range
                    string temp = to_string(nums[start_index]);
                    temp += "->";
                    temp += to_string(nums[i-1]);
                    
                    res.push_back(temp);
                }
                
                start_index = i;
            }
        }
        
        
        // Check the end boundary case
        
        if (start_index == i - 1) // Single element case
        {
            res.push_back(to_string(nums[start_index]));
        }
        else // start_index is behind i ;  // multi element range
        {
            string temp = to_string(nums[start_index]);
            temp += "->";
            temp += to_string(nums[i-1]);
                    
            res.push_back(temp);
        }
        
        /*        
            28 / 28 test cases passed.
            Status: Accepted
            Runtime: 0 ms
            Memory Usage: 7.2 MB
            Submitted: 0 minutes ago

        */
        
        return res;
        
    }
};
