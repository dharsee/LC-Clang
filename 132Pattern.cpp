/*

132 Pattern

Solution
Given an array of n integers nums, a 132 pattern is a subsequence of three integers 
nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 104
-109 <= nums[i] <= 109


3 Solutions:
1 - O(N^3) - O(1)
2 - O(N^2) - O(1)
3 - O(N) - O(N)
*/


class Solution {
public:
    
    
    bool find132pattern(vector<int>& nums) {
        
        // Let's implement O(N^2) solution
        
        int i, j, k, n = nums.size();
        if (n <= 2) return false;
        
        // Build same size vector and keep min till current
        
        vector<int> minVect(n, 0);
        //int minLeft = nums[0];
        minVect[0] = nums[0];
        
        for (i = 1; i < n; i++)
        {
            minVect[i] = min(minVect[i-1], nums[i]);  
        }
        
        // Maintain stack 
        
        stack<int> st;
        
        for (j = n - 1; j >= 0; j--)
        {
            if (nums[j] > minVect[j])
            {
                while (!st.empty() && st.top() <= minVect[j])
                    st.pop();
                if (!st.empty() && st.top() < nums[j]) return true;
                
                st.push(nums[j]);
            }
        }
        
        return false;
        
        /*
        
        // Much improved solution .....
                96 / 96 test cases passed.
        Status: Accepted
        Runtime: 16 ms
        Memory Usage: 13 MB
        Submitted: 0 minutes ago

        */
    }
    
    
    
    bool find132pattern_o2(vector<int>& nums) {
        
        // Let's implement O(N^2) solution
        
        int j, k, n = nums.size();
        if (n <= 2) return false;
        
        int minLeft = nums[0];
        
        for (j = 1; j < n - 1; j++)
        {
            // Check if exist element that is in between minLeft and nums[j]
            for (k = j + 1; k < n; k++)
            {
                if (nums[k] > minLeft && nums[k] < nums[j]) return true;
            }
            
            // Update new min
            minLeft = min(minLeft, nums[j]);
        }
        
        return false;
    }
    
    
    /*
    
    This solution will take O(N^2) and accepted by leetcode server
        96 / 96 test cases passed.
    Status: Accepted
    Runtime: 800 ms
    Memory Usage: 12.6 MB
    Submitted: 0 minutes ago

    */
};

#if 0


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        // Let's implement O(N^2) solution
        
        int i, j, k, n = nums.size();
        if (n <= 2) return false;
        
        
        // map and see if there is any attern like, 0, 1, 0, 0, 1, etc....
        
        unordered_map<int, int> hmap;
        
        for (i = 0; i < n; i ++)
        {
            hmap[nums[i]]++;
        }
        
        if (hmap.size() < 3) return false;
        
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j] + 1)
                {
                    // Check if exist element that is in between nums[i] and nums[j]
                    for (k = j + 1; k < n; k++)
                    {
                        if (nums[k] > nums[i] && nums[k] < nums[j]) return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    
    /*
    
    Nothing wrong with this solution other than taking long and longer time to complete O(N^3)
            91 / 96 test cases passed.
        Status: Time Limit Exceeded
        Submitted: 0 minutes ago
    */
};
#endif
