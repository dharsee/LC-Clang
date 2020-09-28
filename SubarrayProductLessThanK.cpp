/*
 Subarray Product Less Than K

Solution
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
   Hide Hint #1  
For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. opt is an increasing function.

*/
class Solution {
public:
    
    void dump(vector<int> &nums, int start, int end)
    {
        printf(" <");
        while (start < end)
        {
            printf("%d ", nums[start]);
            start++;
        }
        printf(">");
        
    }
        

    void generateSubarray(vector<int> &nums, int start, int k, int &count)
    {
        int i = 0, j, n = nums.size();
        long int prod = 1;
        
        
        for (i = 0; i < n; i++)
        {
            //printf("\n\tStart = %d ", i);
            prod = nums[i];
            //int len = n;
            bool possible = true;
            for (j = i+1; j < n; j++)
            {
                prod = prod * nums[j];
                if (prod < k)
                {
                    count++;
                    //dump(nums, i, j+1);
                }
                else
                {
                    //possible = false;
                    break;
                }
            }
        }
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    
        int count = 0, i, n = nums.size();
        if (n == 0) return 0;
        if (k <= 1) return 0;
        
        
        /*
        // BRUTE-FORCE method, naive method to explore all possible subarray and see if each are conted or not.
        // This is exceeding runtime
        // one-element sub-array
        for (i = 0; i < n; i++)
            if (nums[i] < k) count++;
 
        
        generateSubarray(nums, i, k, count);
        
        */
        
        
        
        // Better appraoch is to use sliding window method described int the answer page.
        int start = 0, end = 0;
        int prod = 1;
        for (end = 0; end < n; end++)
        {
            prod = prod * nums[end];
            
            while (prod >= k)
            {
                prod = prod / nums[start];
                start++;
            }
            
            count += end - start + 1; // This will gives us number of possible sub-arrays with this window size
        }
    
        
        return count;
        
    }
    
    /* 
    Runtime :
    1) Brute-Force method will exhaust runtime
    2) Sliding window method is aking 250 ms
    
    
84 / 84 test cases passed.
Status: Accepted
Runtime: 252 ms
Memory Usage: 92.2 MB
Submitted: 4 minutes ago
    
    */
};
