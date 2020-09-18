/*

561. Array Partition I
Easy

Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].

*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int n = nums.size();
        if (n == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        // now find the sum (min())
        int i, sum = 0;
        
        for (i = 1; i < n; i += 2)
        {
            sum += min(nums[i], nums[i-1]);
        }
        
        return sum;
    }
};

/*
Runtime: 160 ms, faster than 36.58% of C++ online submissions for Array Partition I.
Memory Usage: 28.4 MB, less than 24.22% of C++ online submissions for Array Partition I.
*/
