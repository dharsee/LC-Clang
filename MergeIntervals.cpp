/*
56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of 
the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
Accepted
732,235
Submissions
1,820,972

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // This is important question to understand and code the solution
        
        int n = intervals.size();
        vector<vector<int>> res;
        
        // Sort input intervals based on the start val
        sort(intervals.begin(), intervals.end());
        
        //Add first interval in the result
        res.push_back(intervals[0]);
        
        int i;
        // Now scan from the second index and try to merge
        for (i = 1; i < n; i++)
        {
            //check if we either append or update back;
            if (intervals[i][0] <= res.back()[1]) 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        
        return res;
        
        /*
                Details 
        Runtime: 40 ms, faster than 70.28% of C++ online submissions for Merge Intervals.
        Memory Usage: 14.6 MB, less than 78.04% of C++ online submissions for Merge Intervals.
        
        */
        
    }
};
