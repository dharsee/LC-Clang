/*
Maximize Distance to Closest Person

Solution
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 
represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

 

Example 1:


Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Example 3:

Input: seats = [0,1]
Output: 1
 

Constraints:

2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.

*/


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size();
        if (n < 2) return 0;
        
        int max_gap = 0;
        int start = -1;
        int i;
        
        int gap_at_beginning = -1;
        int gap_at_ending = -1;
  
        if (seats[0] == 0) start = 0;
        
        for (i = 1; i < n; i++)
        {
            if (seats[i-1] == 0 && seats[i] == 1) // occupied and breaking empty row
            {
                if (max_gap < i - start)
                {
                    max_gap = i - start;
                    if (start == 0) gap_at_beginning = max_gap;
                }
                start = -1;
            }
            else if (seats[i-1] == 1 && seats[i] == 1)
                /* Nothing to do */ ;
            else if (seats[i-1] == 0 && seats[i] == 0)
            {
                if (start == -1) start = i - 1;
            }
            else if (seats[i-1] == 1 && seats[i] == 0)
            {
                start = i;
            }
            else
            {
                printf("\n Should not happen ....");
            }
        }
        
        // Determine gap at end
        if (seats[i-1] == 0 && start != -1)
        {
            gap_at_ending = i - start;
        }

        // Gap at middle - tune it according to the even or odd distance
        if (max_gap & 0x1)
            max_gap = 1 + max_gap / 2;
        else
            max_gap = max_gap / 2;
        
        // Since gap at middle was adjusted to proper value, return max of {1, beg, middle, end};
        return max({1, gap_at_beginning, max_gap, gap_at_ending});
        
        /*
                    79 / 79 test cases passed.
            Status: Accepted
            Runtime: 24 ms
            Memory Usage: 17.4 MB
            Submitted: 0 minutes ago
            
                    79 / 79 test cases passed.
        Status: Accepted
        Runtime: 20 ms
        Memory Usage: 17.6 MB
        Submitted: 0 minutes ago


        */
    }
};
