/*
Longest Turbulent Subarray

Solution
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 

Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
Example 2:

Input: arr = [4,8,12,16]
Output: 2
Example 3:

Input: arr = [100]
Output: 1
 

Constraints:

1 <= arr.length <= 4 * 104
0 <= arr[i] <= 109

*/


class Solution {
public:
    
    inline bool isCurrentIndexTurbulent(vector<int>& arr, int indx) {
        
        if ((arr[indx] < arr[indx - 1] && arr[indx] < arr[indx + 1]) /*Valley */ ||
            (arr[indx] > arr[indx - 1] && arr[indx] > arr[indx + 1]) /* Mountain */
           )
            return true;
        
        return false;
        
    }
    
    
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();
        
        if (n < 2) return n;
        
        int start = 0, end = 0, len = 0;
        int maxlen = 1; // Can be considered for equal elements in the array
        
        
        while (start + 1 < n) {
            
            // Case where flat curve
            if (arr[start] == arr[start+1]) { 
                start++; 
                continue;
            }
            
            end = start + 1;
            while ((end + 1 < n) && isCurrentIndexTurbulent(arr, end)) 
                end++;
            
            if (maxlen < (end-start+1))
                maxlen = end - start + 1;
            
            start = end;
        }
        
        return maxlen;
    }
};

/*
89 / 89 test cases passed.
Status: Accepted
Runtime: 89 ms
Memory Usage: 40.2 MB
Submitted: 3 hours, 16 minutes ago


*/
