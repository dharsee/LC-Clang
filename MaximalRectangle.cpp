/*
85. Maximal Rectangle
Hard - 5792  - 102 - Add to List - Share

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.


*/

class Solution {
public:
    
    int find_maxRect_in_hist(vector<int> &hist) {
        int n = hist.size();
        if (n == 0) return 0;
        else if (n == 1) return hist[0];
        
        // Maintain two vectors to track left and right indices of the current one
        // which has less than this value.
        
        vector<int> left(n, 0), right(n, 0);
        int i;
        
        // Maintain the stack to track the ordering of the indices which are having less than 
        // current one
        stack<int> st;
        
        // Find LEFT indices
        for (i = 0; i < n; i++) {
            if (!st.empty()) {
                
                while (!st.empty() && hist[st.top()] >= hist[i]) st.pop();
                
                if (st.empty()) left[i] = 0; // left boarder
                else left[i] = st.top() + 1;
                
                st.push(i);
                
            } else {
                left[i] = i;
                st.push(i);
            }
        }
        
        // Empty the stack to re-use
        while (!st.empty()) st.pop();
        
        // Find RIGHT indices
        for (i = n - 1; i >= 0; i--) {
            if (!st.empty()) {
                
                while (!st.empty() && hist[st.top()] >= hist[i]) st.pop();
                
                if (st.empty()) right[i] = n - 1; // left boarder
                else right[i] = st.top() - 1;
                
                st.push(i);
                
            } else {
                right[i] = i;
                st.push(i);
            }
        }
        
        // Now compute the max_area
        int max_area = 0, curr_area = 0;
        
        for(i = 0; i < n; i++) {
            curr_area = hist[i] * (right[i] - left[i] + 1);
            if (curr_area > max_area) max_area = curr_area;
        }
        
        return max_area;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        // This problem has a sub-problem of finding the max rectangle are in the given 
        // histgram
        
        // We use dynamic prograaming methodology to optimize time complexity
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        // Maintain a vector of size col
        vector<int> dp(col, 0);
        
        // Copy first row to the dp
        // Since given input is in char lets change it to num
        int i;
        int max_area = 0;
        int curr_area = 0;
        for (i = 0; i < col; i++) {
            dp[i] = matrix[0][i] - 48;
            if (dp[i] == 0) {
                if (curr_area > max_area) max_area = curr_area;
                curr_area = 0;
            } else curr_area++;
        }
        if (curr_area > max_area) max_area = curr_area;
        
        
        
        for (i = 1; i < row; i++) {
            int curr_max = 0;
            for (int j = 0; j < col; j++) {
                int curr = matrix[i][j] - 48;
                if (curr) {
                    dp[j] += curr;
                } else {
                    dp[j] = 0;
                }
                curr_max = max(curr_max, dp[j]);
            }
            //max_area = max(max_area, curr_max);
            curr_max = find_maxRect_in_hist(dp);
            max_area = max(max_area, curr_max);
        }
        
        return max_area;
    }
};






/*

Success
Details 
Runtime: 48 ms, faster than 19.82% of C++ online submissions for Maximal Rectangle.
Memory Usage: 14.5 MB, less than 13.49% of C++ online submissions for Maximal Rectangle.


*/
