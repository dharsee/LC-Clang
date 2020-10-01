/*
First Missing Positive

Solution
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.

   Hide Hint #1  
Think about how you would solve the problem in non-constant space. Can you apply that logic to the existing space?
   Hide Hint #2  
We don't care about duplicates or non-positive integers
   Hide Hint #3  
Remember that O(2n) = O(n)


*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // This is similar to finding missing number from 1 TO n, where n is size of array
        int i, n = nums.size();
        int j, k,l;
        
        // Not striaght forward, but we need to transform input array to that form and then apply 
        // same alogothm to find first positive 
        
        // TRANFORM input array by following this rule
        // Consider all possible values must be 1 TO n + 1 (where n is size of input array)
        // scan input array and fill with 1 if element is <= 0 or > n
        
        bool one_present = false;
        for (i = 0; i < n; i++)
        {
            if (nums[i] == 1) one_present = true;
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1; // we need to consider 0 in this range
        }
        
        
        // one_present variable will handle below inputs; otherwise its tough to indetify
        // [7,8,9,11,12]
        if (one_present == false) return 1;
        
        // NOW Array contains in the range of 1 TO n + 1; (since 0 is not part)
        // Now scan array and change its index sign to negative (skip if its already negative)
        
        for (i = 0; i < n; i++)
        {
            int ele_as_index = abs(nums[i]);
            if(nums[ele_as_index - 1] > 0) // POSITIVE 
                nums[ele_as_index - 1] = -nums[ele_as_index - 1];
        }
        
        /*
        
        // DUMP
        printf("\nAfter transform and flip sign : ") ;
        for (i = 0; i < n; i++)
            printf("%d, " ,nums[i]);
        */
        
        // Now scan array once again to find the first index which is having positive element.
        for (i = 0; i < n; i++)
            if (nums[i] > 0) return i+1;
        
        // This indicates first n numbers are present and first positive missing is next number (n+1)
        // Where n is number of elements in the array
        return i+1;
    }
    
    /*

165 / 165 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 10 MB
Submitted: 0 minutes ago

    
    */
};
