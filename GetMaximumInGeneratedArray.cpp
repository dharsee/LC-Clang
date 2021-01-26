/*
1646. Get Maximum in Generated Array
Easy

You are given an integer n. An array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.

 

Example 1:

Input: n = 7
Output: 3
Explanation: According to the given rules:
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.
Example 2:

Input: n = 2
Output: 1
Explanation: According to the given rules, the maximum between nums[0], nums[1], and nums[2] is 1.
Example 3:

Input: n = 3
Output: 2
Explanation: According to the given rules, the maximum between nums[0], nums[1], nums[2], and nums[3] is 2.
 

Constraints:

0 <= n <= 100
*/

class Solution {
public:
    
    void print_v(vector<int> &v)
    {
        vector<int>::iterator iter = v.begin();
        printf("\n");
        while (iter != v.end())
        {
            printf("%d ", *iter);
            iter++;
        }
        printf("\n");
    }
    int getMaximumGenerated(int n) {
        
        if (n <= 1) return n;
        
        int maxn = 1;
        int i = 0;
        
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
   
        for (i = 2; i <= n; i++)
        {
            int index = i / 2;
            int val = v[index];
            
            if (i & 0x1) { // ODD index
                val += v[index + 1];
                v.push_back(val);
                
            } else { // EVEN index
                v.push_back(val);
            } 
            
            if (val > maxn) maxn = val;
        }
        
        // print_v(v);
        
        return maxn;
    }
    
    /*
    
    Success
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Get Maximum in Generated Array.
Memory Usage: 6.1 MB, less than 68.12% of C++ online submissions for Get Maximum in Generated Array.
    */
};
