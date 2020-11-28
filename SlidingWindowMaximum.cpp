/*

Sliding Window Maximum

Solution
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
   Hide Hint #1  
How about using a data structure such as deque (double-ended queue)?
   Hide Hint #2  
The queue size need not be the same as the window’s size.
   Hide Hint #3  
Remove redundant elements and the queue should store only elements that need to be considered.

*/


class Solution {
public:
    
    void display(vector<int> &A, int k)
    {
        int i, n = A.size();
        
        
        printf("\n i = %d  ===> ", k);
        for (i = 0; i < n; i ++)
            printf("%d, ", A[i]);
        
        
    }
    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        int n = nums.size();
        
        if (k == 1) return nums;
        
        if (k < 1 || k > n) return {}; // Negative test case
        
        // Maintain deque to keep max elements until now
        
        deque<int> dq;
        int i;
        
        // Load first k elements into dq with this property
        for (i = 0; i < k - 1; i++)
        {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            
            dq.push_back(nums[i]);
        }
        
        // For rest of the vector
        for (i = k - 1; i < n; i++)
        {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            
            dq.push_back(nums[i]);
            
            // Now add front element to res
            res.push_back(dq.front());
            
            if (nums[i-k+1] == dq.front())
                dq.pop_front();
        }
     
        return res;
        
        /*
                59 / 59 test cases passed.
        Status: Accepted
        Runtime: 364 ms
        Memory Usage: 107.1 MB
        Submitted: 0 minutes ago

        */
    }
    
    
    
    vector<int> maxSlidingWindow_BruteForce_TME(vector<int>& nums, int k) {
        
        vector<int> res;
        int n = nums.size();
        
        if (k == 1) return nums;
        
        if (k < 1 || k > n) return {}; // Negative test case
        
        // Assume first index is the max of all in this window
        int curr_max = nums[0];
        int max_index = 0;
        
        // find max at first window and keep the index where we have seen it.
        int i = 0;
        for (i = 1; i < k; i++)
        {
            if (nums[i] > curr_max)
            {
                curr_max = nums[i];
                max_index = i;
            }
        }
        
        res.push_back(curr_max);
        
        while(i < n)
        {
            //display(res, i-k);
            // compare this with last seen max
            if (curr_max > nums[i]) // No change case
            {
                //printf("\n i = %d, has windows max at {%d, %d} [left : %d] ", 
                //       i, max_index, curr_max, i - k + 1);
                if (max_index >= i - k + 1)
                {
                    //printf(" --- pushing curr_max = %d to RESULT ", curr_max);
                    res.push_back(curr_max);
                }
                else
                {
                    // expired, need to compute new max for this window
                    int j = i - k + 1;
                    //printf(" --- Re-computing max, k = %d, i = %d, j = %d, max_index = %d, curr_max = %d ", k, i, j, max_index, curr_max);
                    
                    curr_max = nums[j];
                    max_index = j;
                    int m = 1;
                    for (j = j + 1; j < n && m < k; j++, m++)
                    {
                        if (nums[j] > curr_max)
                        {
                            curr_max = nums[j];
                            max_index = j;
                        }
                        
                    }
                    //printf(" ------ res : curr_max = %d ", curr_max);
                    res.push_back(curr_max);
                }
            }
            else
            {
                //printf("\n i = %d, This element is max of curr window, previous {%d, %d} ", i, max_index, curr_max);
                curr_max = nums[i];
                max_index = i;
                
                res.push_back(curr_max);
            }
            
            i++;
        } // EDN of while loop
        
        
        return res;
        
        /*
                    59 / 59 test cases passed, but took too long.
            Status: Time Limit Exceeded
            Submitted: 0 minutes ago

        
        */
        
        
    }
};

