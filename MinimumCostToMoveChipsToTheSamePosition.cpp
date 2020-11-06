/*

1217. Minimum Cost to Move Chips to The Same Position
Easy

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

 

Example 1:


Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
Example 2:


Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at poistion 3 to position 2. Each move has cost = 1. The total cost = 2.
Example 3:

Input: position = [1,1000000000]
Output: 1
 

Constraints:

1 <= position.length <= 100
1 <= position[i] <= 10^9
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int n = position.size();
        
        // Since we know that all even position to move cost will be 0
        // and odd position to move cost wil be 1
        // Algorithms would be: 
        // Sum even position chips and odd position chips and return min of these two
        
        int i, odd_cnt = 0, even_cnt = 0;
        
        for (i = 0; i < n; i++)
        {
            if (position[i] & 0x1) odd_cnt++;
            else even_cnt++;
        }
        
        return min(even_cnt, odd_cnt);
        
        
        
        /*
        
        Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
Memory Usage: 7.6 MB, less than 77.93% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
        */
        
    }
};
