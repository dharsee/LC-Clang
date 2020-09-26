/*
645. Set Mismatch
Easy

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got
duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice
and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.

*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        int i;
        
        vector<int> res;
        
        // There will be many ways to solve this problem, I am choosing one has O(N) runtime and O(1) space complexity
        // Since array will contains 1 .. n and one of them is missed which is caused to repeat other number
        // I will be using input array to mark its present and in later scan I will find one which is missing
        
        // PASS - 1: To mark presence of each number in the range of 1 to N.
        
        for (i = 0; i < n; i++)
        {
            int index = abs(nums[i]);
            if (nums[index - 1] < 0) // Duplicate
                res.push_back(abs(nums[i]));
            else
                nums[index - 1] = -nums[index - 1];
        }
        
        //if (res.size() > 0)
        //    printf("\n Duplicate : %d" , res[0]);
        // PASS - 2
        // We have found the repeated one
        // Now we will find the missing one, it should be the index where you see the positive num
        //printf("\n");
        for (i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                res.push_back(i + 1);
                break;
            }
        }
        
        return res;
        
    }
    
    /*
    Success
Details 
Runtime: 52 ms, faster than 89.91% of C++ online submissions for Set Mismatch.
Memory Usage: 21.8 MB, less than 43.55% of C++ online submissions for Set Mismatch.
    
    */
};
