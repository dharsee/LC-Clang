/*
Insert Interval

Solution
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 105
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 105

*/
class Solution {
public:
    
    void dump(vector<vector<int>> &in, char *msg)
    {
        int i, n = in.size();
        
        cout << endl << msg;
        
        for(i = 0; i < n; i++)
            printf(" [%d, %d]", in[i][0], in[i][1]);
        
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
     
        int ni = intervals.size();
        int nni = newInterval.size();
        
        if (ni == 0) return {newInterval};
        
        int i, j, k;
        
        vector<vector<int>> res;
        vector<int> mi(2);
        mi[0] = INT_MAX;
        mi[1] = INT_MIN;
        
        // First copy all the non-overlapping intervals at the beginning
        vector<int> t(newInterval);
        
        bool new_inserted = false;
        if (newInterval[1] < intervals[0][0])
        {
            res.push_back(newInterval);
            new_inserted = true;
        }
        
        
        for (i = 0; i < ni; i++)
        {
            if (intervals[i][1] < t[0])
            {
                res.push_back(intervals[i]);
            }
            else
                break;
        }
        
        //dump(res, "After 1st Pass:");
        
        
        // Copy overlap intervals
        for (; i < ni; i++)
        {
            int x1 = intervals[i][0], y1 = intervals[i][1];
            int x2 = t[0], y2 = t[1];
            
            /*
            if ( (x2 >= x1 && x2 <= y1) || (y1 >= x2 && y1 <= y2) || 
                 (x2 >= x1 && y2 <= y1) || (x1 >= x2 && y2 <= y1) )
                
            if ( (x2 >= x1 && x2 <= y1) || (y1 >= x2 && y1 <= y2) || 
                 (y2 >= x1 && y2 <= y1) || (x1 >= x2 && x2 <= y2) )
                 */
            if ( (x2 >= x1 && x2 <= y1) || (y1 >= x2 && y1 <= y2) || 
                 (y2 >= x1 && y2 <= y1) || (x1 >= x2 && x1 <= y2) )
            
            {
                mi[0] = min({x1, x2, mi[0]});
                mi[1] = max({y1, y2, mi[1]});
            }
            else break;
            
            //printf("\n i = %d and mi[%d, %d] ", i, mi[0], mi[1]);
        }
        
        //printf("\n Done 1");;
        if (mi[0] != INT_MAX)
        {
            res.push_back(mi);
            t[0] = -1;
            t[1] = -1;
        }
        else if (new_inserted == false)
        {
            res.push_back(t);
            t[0] = -1;
            t[1] = -1;
        }
        
        /*
        dump(res, "After overlap Pass:");
        
        printf("\n Done 2");;
        // Copy rest of the interals if any exists
        */
        for (; i < ni; i++)
        {
            res.push_back(intervals[i]);
        }
        
        if (t[0] != -1 && new_inserted == false)
        {
            res.push_back(t);
            //sort(res.begin(), res.end());
            // This can be taken off when line 85 - 90 lines were added
            // These two were exclusive
        }
        
        
        
        // return result;
        
        return res;
    }
};
