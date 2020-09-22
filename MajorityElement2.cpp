/*
Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
   Hide Hint #1  
How many majority elements could it possibly have?
Do you have a better hint? Suggest it!

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        
        int i;
        
        // Define 2 counters and 2 candidates
        int cntr1 = 0, cntr2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        
        // PASS 1 -  To find the potential candidates which can be majority elemnts in the array
        
        for (i = 0; i < n; i++)
        {
            if (candidate1 != INT_MIN && candidate1 == nums[i])
                cntr1++;
            else if (candidate2 != INT_MIN && candidate2 == nums[i])
                cntr2++;
            else if (cntr1 == 0)
            {
                candidate1 = nums[i];
                cntr1 = 1;
            }
            else if (cntr2 == 0)
            {
                candidate2 = nums[i];
                cntr2 = 1;
            }
            else // Case when current element is not matching with either of candidates
            {
                cntr1--;
                cntr2--;
            }
        }
        
         // Now we have 2 candidates and if the arrays has two majority element the should be from these 2 only
        
        // In this pass we will validate their majority 
        // {this is needed because sometime there might no majority elements at all}      
        
        // PASS 2 - to validate the candidature if they still be the majority or not by actual count/freq
        
        bool f = false, s = false;
        cntr1 = 0;
        cntr2 = 0;
        
        for (i = 0; i < n; i ++)
        {
            if (candidate1 == nums[i])
                cntr1++;
            else if (candidate2 == nums[i])
                cntr2++;
            
            if (!f && cntr1 > n / 3)
            {
                res.push_back(candidate1);
                f = true;
            }
            
            if (!s && cntr2 > n / 3)
            {
                res.push_back(candidate2);
                s = true;
            }
            
            if (s && f) break;
        }
        
        return res;
    }
};


/*

66 / 66 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 15.5 MB
Submitted: 0 minutes ago


*/
