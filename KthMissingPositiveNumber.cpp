/*
1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length

*/

class Solution {
public:
    
    void dump(vector<int> &v)
    {
        int i, n = v.size();
        
        printf("\n");
        for (i = 0; i < n; i++)
            printf(" %2d", v[i]);
            
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        
        int i, j, l;
        
        int n = arr.size();
        
        vector<int> missing;
        
        j = 1;
        for (i = 0; i < n; )
        {
            if (arr[i] == j)
            {
                i++;
                j++;
                continue;
            }
            else
            {
                //printf("\n [%d] Need to push from %d to %d ", i, j, arr[i]);
                while (j < arr[i])
                {
                    missing.push_back(j);
                    j++;
                }
            }
            
            //dump(missing);
        }
        
        
        //dump(missing);
        
        int msz = missing.size();
        //printf("\nat End msz = %d k = %d", msz, k);
        
        
        if (msz == 0)
        {
            return arr[n-1] + k;
        }
        
        if (k <= msz)
        {
            return missing[k-1];
        }
        else
        {
            //return (k-msz) + missing[msz-1];
            return (k-msz) + arr[n-1];
        }
        
    }
};


/*

Result 
Success
Details 
Runtime: 12 ms, faster than 63.23% of C++ online submissions for Kth Missing Positive Number.
Memory Usage: 10.1 MB, less than 29.17% of C++ online submissions for Kth Missing Positive Number.



*/
