/*
169. Majority Element
Easy

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/


class Solution {
public:
    
    // Previous solution was using sort which has rumtime complexity is O(NlongN)
    // This solution will follow <Moore's Voting> algorithm to find the
    // majority of an array
    
    int majorityElement(vector<int>& nums) {
    
        int n = nums.size();
        if (n == 0) return 0;
        
        int res, i;
        
        int counter = 1, candidate = nums[0];
        
        // PASS 1 - find the candidate among array elements
        for (i = 1; i < n; i++)
        {
            if (candidate == nums[i])
                counter++;
            else counter--;
            
            if (counter == 0)
            {
                candidate = nums[i];
                counter = 1;
            }
        }
        
        
        // For this purticular problem statement, we can return the candidate without checking the next pass
        
        return candidate;
        
        // PASS 2 - To validate its candidature
        // In this problem this is not required, since it was stated that there will be a majority element exists
        // for guarantee
        
        counter = 0;
        for (i = 0; i < n; i++)
        {
            if (candidate == nums[i]) counter++;
            
            if (counter > n / 2) return candidate;
        }
        
        return -1;
    }
};


/*
46 / 46 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 19.6 MB
Submitted: 1 minute ago



*/
