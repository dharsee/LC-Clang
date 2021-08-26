/*
1508. Range Sum of Sorted Subarray Sums

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
 

Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2

*/


class Solution {
public:
    
    long long int mod = (long long int)(pow(10, 9) + 7);
    
    void printVec(vector<int>& nums) {
        
        cout << endl << "Vector :";
        
        auto iter = nums.begin();
        
        while (iter != nums.end()) {
            cout << *iter << ", ";
            iter++;
        }
    }
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        int sz = n * (n+1) / 2;
        vector<int> LA(sz, 0);
        
        int i, j, k = 0;
        
        for (i = 0; i < n; i++)
        {
            LA[k++] = nums[i];
            int sum = nums[i];
            for (j = i + 1; j < n; j++) {
                sum = sum + nums[j];
                LA[k++] = sum;
            }
        }
        
        // printVec(LA);
        sort(LA.begin(), LA.end());
        // cout << endl << "Sorted : ";
        // printVec(LA);
                

        
        int sum = 0;
        for (i = left; i <= right; i++) {
            sum = (sum + LA[i-1]) % mod;
            // sum = sum % (long long int)(pow(10, 9) + 7);
        }
        
        return sum;
    }
};


/*

54 / 54 test cases passed.
Status: Accepted
Runtime: 104 ms
Memory Usage: 15.6 MB
Submitted: 1 minute ago


*/
