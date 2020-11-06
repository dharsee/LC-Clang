/*
Find the Smallest Divisor Given a Threshold

Solution
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide 
all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
Example 3:

Input: nums = [19], threshold = 5
Output: 4
 

Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6
   Hide Hint #1  
Examine every possible number for solution. Choose the largest of them.
   Hide Hint #2  
Use binary search to reduce the time complexity.

*/


class Solution {
public:
    
    long int compute(vector<int> &nums, int d)
    {
        long int s = 0;
        int i = 0, n = nums.size();
        for (; i < n; i++)
        {
            s += (nums[i] / d) + (nums[i] % d == 0 ? 0 : 1);
        }
        
        return s;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        // First find the bounderies for the divisor
        
        int left = 1, right = 2;
        
        while (compute(nums, right) > threshold)
        {
            left = right;
            right <<= 1; // Doubling right
        }
        
        // Now perform Binary search to find best divisor
        
        while (left  <= right)
        {
            int mid = (right - left) / 2 + left;
            
            long int n = compute(nums, mid);
            
            if (n > threshold)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        /*
        
        Success
Details 
Runtime: 80 ms, faster than 34.55% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
Memory Usage: 20.4 MB, less than 5.65% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
        */
        
        
        
        return left;
    }
    
#if 0
    /*
        This is Brute-Force method and exceeds TL.
    */
    int compute(vector<int> &nums, int d)
    {
        int s = 0;
        int i = 0, n = nums.size();
        for (; i < n; i++)
        {
            s += (nums[i] / d) + (nums[i] % d == 0 ? 0 : 1);
        }
        
        return s;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int d = 1;
        
        //int n = nums.size();
        
        while(compute(nums, d) > threshold) d++;
        
        return d;
    }
#endif
};
