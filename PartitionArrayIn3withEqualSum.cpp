/*
1013. Partition Array Into Three Parts With Equal Sum

Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

Example 1:

Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
Example 2:

Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false
Example 3:

Input: A = [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

Constraints:

3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4

*/


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        
        int n = A.size();
    
        if (n <= 2) return false;
        
        int i;
        
        long int s1 = 0;
        
        // scan whole arrays to find sum
        for (i = 0; i < n; i++) s1 += A[i];
        
        // early termination, since whole sum should be 3X
        if (s1 % 3) return false;
        
        
        int count = 0;
        long int third = s1 / 3;
        long curr_sum = 0;
        
        // Now again scan the array and look for cumulative sum equal third then increment count and reset sum to 0
        
        for (i = 0; i < n; i++)
        {
            curr_sum += A[i];
            if (curr_sum == third)
            {
                count++;
                s1 -= curr_sum;
                
                
                // This is good optimization for 3rd part, runtime 92 ms vs 104 ms
                if (count == 2)
                {
                    if (s1 == third && i < n - 1) return true;
                }
                
                curr_sum = 0;
            }
        }
        
        // Adding = to this relation op is good idea since in the loop it may increase for 0 cae
        if (count >= 3) return true;
     
        
        //printf("\n count = %d, s1 = %d third = %d, curr_sum = %d", count, s1, third, curr_sum);
        return false;
    }
};
