/*

Remove Covered Intervals

Solution
Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
Example 3:

Input: intervals = [[0,10],[5,12]]
Output: 2
Example 4:

Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2
Example 5:

Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= intervals[i][0] < intervals[i][1] <= 10^5
All the intervals are unique.


  Hide Hint #1  
How to check if an interval is covered by another?
   Hide Hint #2  
Compare each interval to all others and check if it is covered by any interval.


*/



class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // Lets try witn O(N^2) solution
        // This will take longer time due to erase op on intervals and running loop ~ O(N^2)
        
        int i, j, k, l; 
        int r = intervals.size();
        int count = 0;
        
        if (r <= 1) return r;
        
        for (i = 0; i < intervals.size(); i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];
                
            for (j = 0; j < intervals.size(); j++)
            {
                if (i == j) continue;
                
                int c = intervals[j][0];
                int d = intervals[j][1];
                
                //printf("\n I (%d, %d)  J(%d, %d) Working set ..", a, b, c, d);
                if (a <= c && d <= b)
                {
                    // this is coverd by other so remove it
                    intervals.erase(intervals.begin() + j);

                    i--; // This is needed to reconsider
                    break;
                } 
                
                else if (a >= c && d >= b)
                {    
                    intervals.erase(intervals.begin() + i);
                    i--; // This is needed to reconsider
                    break;
                }
            }
        }

        return intervals.size();
    }
    
    /*
    32 / 32 test cases passed.
Status: Accepted
Runtime: 572 ms
Memory Usage: 11.6 MB
Submitted: 0 minutes ago

    
    */
};


//Optimized version, O(NlogN) where N - length of intervals arrays;due to sort



class Solution {
public:
    
    // Optimized version
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // Optimized over brute force method
        // Sort intervals based on starting point
        
        int i;
        int count = 0;
        
        if (intervals.size() <= 1) return intervals.size();;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> curr(2, -1);
        
        for (i = 0; i < intervals.size(); i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];
            
            if (a > curr[0] && b > curr[1])
            {
                count++;
                curr[0] = a;
            }
            
            curr[1] = max(b, curr[1]);
        }
        
        return count;
    }
 /*
 32 / 32 test cases passed.
Status: Accepted
Runtime: 48 ms
Memory Usage: 11.5 MB
Submitted: 0 minutes ago

 
 */
 
};
