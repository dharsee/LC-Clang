/*
 Car Pooling

Solution
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
 
 

Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
   Hide Hint #1  
Sort the pickup and dropoff events by location, then process them in order.

*/

class Solution {
    
    // This may take extra time to scan, this is linear search
    // This would cost O(N ^ 2)
    void re_scan(vector<vector<int>>& trips, int k, int &avail)
    {
        int i = 0;
        
        while (i < k)
        {
            if (trips[i][0] > 0) // -ve number of passengers indicates, it was already considered
            {
                //if (dist >= trips[i][2])
                if (trips[k][1] >= trips[i][2])
                {
                    avail += trips[i][0];
                    trips[i][0] = -1; // Marking this as -ve, since it is considred
                    // By end of all trip, all the passengers slot should be -ve
                }
            }
            i++;
        }
    }
    
    void dump(vector<vector<int>> &trips)
    {
        int i, n = trips.size();
        
        printf("\n");
        for (i = 0; i < n; i++)
        {
            printf(" <%d, %d, %d>", trips[i][0], trips[i][1], trips[i][2]);
        }
        printf("\n");
        
    }
    
    
public:
    
    bool cust_comp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int i, j, k, l, n = trips.size();
        
        if (n <= 0) return true;
        
        // Sort input vector based on the starting location to work with algorithm to find the solution
        // Run time for this may be O(N log N)
        sort(trips.begin(), trips.end(), 
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        
        //dump(trips);
        
        
        // Scan through trips and check available seats to number of people ready to borad
        // When you have reached destination, drop off them so that available seats will increase
        int avail = capacity;
        
        for (i = 0; i < n; i++)
        {           
            // Go and scan all the previous trips if they were completed at this dist 
            // Re-fresh / Update avail seats
            re_scan(trips, i, avail);
            
            //printf("\n i = %d, avail = %d , capacity = %d  dist = %d", i, avail, capacity, dist);
            if (avail >= trips[i][0])
            {
                avail -= trips[i][0];
            } 
            else
            {
                return false;
            }
            
            //printf(" -- Post avail = %d ", avail);
        }
        
        return true;
    }
};

/*
54 / 54 test cases passed.
Status: Accepted
Runtime: 40 ms
Memory Usage: 9.6 MB


*/
