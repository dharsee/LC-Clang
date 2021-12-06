/*
84. Largest Rectangle in Histogram
Hard 7840 120 Add to List  Share

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104



*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // Maintaine two arrays of same len to track
        // left index which has less than this index
        // right index which has less than this index
        
        int n = heights.size();
        if (n == 0) return 0;
        else if (n == 1) return heights[0];
        
        vector<int> left(n, 0), right(n, 0);
        
        // you need to maintain stack to track the order to avoid O(N^2) TC
        stack<int> st;
        int i, j;
        
        // Track Left indices
        for (i = 0; i < n; i++) {
            if (!st.empty()) {
                
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) left[i] = 0;
                else left[i] = st.top() + 1;
            } else {
                left[i] = i;
            }
            st.push(i);
        }
        /*
        // DEBUG  - print LEFT
        cout << endl << "LEFT : ";
        for (i = 0; i < n; i++)
            cout << left[i] << ", ";
        cout << endl;
        */
        
        // Empty the current stack to re-use
        while (!st.empty()) st.pop();
        
        // Do the same for RIGHT indices tracking
        for (i = n - 1; i >= 0; i--) {
            if (!st.empty()) {
                
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) right[i] = n-1;
                else right[i] = st.top() - 1;
            } else {
                right[i] = i;
            }
            st.push(i);
        }
        
        /*
        // DEBUG  - print LEFT
        cout << endl << "RIGHT : ";
        for (i = 0; i < n; i++)
            cout << right[i] << ", ";
        cout << endl;
        */
        
        
        int max_area = 0;
        
        // Now walk through left and right arrays to compute max area
        
        for (i = 0; i < n; i++) {
            int this_area = heights[i] * (right[i] - left[i] + 1);
            if (this_area > max_area) max_area = this_area;
        }
        
        return max_area;
        
        
    }
};







/*
Success
Details 
Runtime: 120 ms, faster than 73.87% of C++ online submissions for Largest Rectangle in Histogram.
Memory Usage: 66.3 MB, less than 35.68% of C++ online submissions for Largest Rectangle in Histogram.

*/
