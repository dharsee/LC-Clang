/*
1588. Sum of All Odd Length Subarrays

Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000

*/


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       
        // Lets work on bruteForce method to solve this problem
        // 
        int i, j, l;
        int sum = 0, curr_sum = 0;
        int n = arr.size();
        for (i = 0; i < n; i++) sum += arr[i];
        
        int whole_sum = 0;
        if (n > 1 && (n & 0x1)) // Odd len array
            whole_sum = sum;
        
        l = 3; // represent length of subarray and start with 1 element in it
        
        while (l < n) {
            
            curr_sum = 0;
            j = 0;
            while (j < l) {
                curr_sum += arr[j];
                j++;
            }
            
            sum += curr_sum;
            // Extend it further
            
            while (j < n) {
                curr_sum -= arr[j-l]; 
                curr_sum += arr[j];
                j++;
                sum += curr_sum;
            }
            
            l += 2;    
        }

    return sum + whole_sum;
    }
};
