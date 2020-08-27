/*
Find Right Interval

Solution
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
 

Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
 

Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
 

Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


*/


class Solution {
public:
    
    // Binary search will try to find next interval of the input interval based on start
    // If I dont add call-by-ref for the vector, its exceeding timelimit,
    // good to remember that larger arrays would really takes longer time to copy on stack
    // wherever possible optimize with pass-by-reference 
    int bin_search(vector<pair<pair<int, int>, int>> &ordered_interval, int target)
    {
        int n = ordered_interval.size();
        
        // Early trerminate if there is possible right for this intervals
        if (ordered_interval[n-1].first.first < target) return -1;
        
        int l = 0, h = n - 1;
        
        while (l <= h)
        {
            int mid = l + ( h - l) / 2;
            
            if (ordered_interval[mid].first.first >= target) h = mid - 1;
            else l = mid + 1;
        }
        
        return ordered_interval[l].second;
    }
    
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<pair<pair<int, int>, int>> ordered_interval;
        // {<start, end>, index}
        
        // Copy input interval into this data structure and sort it based on the start interval
        // Sorting will help us to find right interval within O(log n) time
        
        int i = 0;
        int n = intervals.size();
        while (i < n)
        {
            ordered_interval.push_back({{intervals[i][0], intervals[i][1]}, i});
            i++;
        }
        
        // Now sort it keeping default arguments so that it will sort based on the starting intervals
        
        sort(ordered_interval.begin(), ordered_interval.end());
        
        // Build the result vector for each of the input intervals
        vector<int> res(n, -1);
        
        // Find Next of each intervals
        for (i = 0; i < n; i++)
        {
            res[i] = bin_search(ordered_interval, intervals[i][1]);
        }
    
        return res;
        
    }
};
