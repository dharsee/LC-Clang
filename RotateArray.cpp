/*
Rotate Array

Solution
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
   Hide Hint #1  
The easiest solution would use additional memory and that is perfectly fine.

Hide Hint #2  

The actual trick comes when trying to solve this problem without using any additional memory. 
This means you need to use the original array somehow to move the elements around. 
Now, we can place each element in its original location and shift all the elements around it to 
adjust as that would be too costly and most likely will time out on larger input arrays.

Hide Hint #3  

One line of thought is based on reversing the array (or parts of it) to obtain the desired result. 
Think about how reversal might potentially help us out by using an example.

Hide Hint #4  
The other line of thought is a tad bit complicated but essentially it builds on the idea of placing each element in 
its original position while keeping track of the element originally in that position. Basically, at every step, 
we place an element in its rightful position and keep track of the element already there or the one being overwritten 
in an additional variable. We can't do this in one linear pass and the idea here is based on cyclic-dependencies between elements.
*/

class Solution {
public:
    
    void dump(vector<int> &v)
    {
        int n = v.size();
        
        int i = 0;
        
        while (i < n)
        {
            printf(" %d ", v [i]);
            i++;
        }
        
    }
    
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            int t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            
            start++;
            end--;
        }
    }
    
    
    void rotate(vector<int>& nums, int k) {
        
        /* 
            Method #2, using Reverse strategy, 
            1. Reverse full array
            2. Reverse two sub-arrays at boundray k
            
        */
        
        int n = nums.size();
        if (n <= 1 || k == 0) return;
        
        
        int newk = k % n;
   
        // 1. Reverse Whole Array
        reverse(nums, 0, n - 1);

        // 2. Reverse last k elements
        reverse(nums, 0, newk - 1);
        
        // 3. Reverse first n - k elements
        reverse(nums, newk, n - 1);
        
        /*        
            35 / 35 test cases passed.
            Status: Accepted
            Runtime: 8 ms
            Memory Usage: 10.3 MB

            
        */
    }
    
    
    void rotate_extra_space(vector<int>& nums, int k) {
        
        /* 
            Method #1, using extra memory O(N)
        */
        int n = nums.size();
        vector<int> res(n, 0);
        
        int newk = k % n;
        
        // First copy last k element to thr result
        copy(nums.begin() + (n - newk), nums.end(), res.begin());
        
        //dump(res);
        // Copy n - k from begin
        copy(nums.begin(), nums.begin() + (n - newk), res.begin() + newk);
        
        nums = res;
        
        /*        
            35 / 35 test cases passed.
            Status: Accepted
            Runtime: 8 ms
            Memory Usage: 10.4 MB
            Submitted: 0 minutes ago
        */
    }
};
