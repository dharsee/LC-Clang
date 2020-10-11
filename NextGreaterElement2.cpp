/*
503. Next Greater Element II
Medium

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search 
circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        // Let's write O(N^2) Solution
        
        int n = nums.size();
        int i = 0, j = 0;
        
        vector<int> res;
        if (n == 0) return res;
        
        if (n == 1) return {-1};
        
        for (i = 0; i < n; i++)
        {
            j = (i + 1) % n;
            bool found = false;
            
            //printf("\nLooking for i = %d and starting from %d ", i, j);
            while (i != j)
            {
                //printf("\n\t J = %d ", j);
                if (nums[i] >= nums[j])
                    j = (j + 1) % n;
                else
                {
                    res.push_back(nums[j]);
                    found = true;
                    break;
                }
            }
            
            if (found == false)
                res.push_back(-1);
        }
        
        return res;
    }
    
    
    /*
    
    This is Bruteforce method; we can optimize it by taking advantage of last index
    Success
Details 
Runtime: 456 ms, faster than 5.98% of C++ online submissions for Next Greater Element II.
Memory Usage: 24.6 MB, less than 5.18% of C++ online submissions for Next Greater Element II.
    
    */
};

