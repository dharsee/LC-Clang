/*
Gas Station

Solution
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

*/


class Solution {
    
    int check(vector<int>& gas, vector<int>& cost, int start_index)
    {
        int i, j, k, l;
        int n = cost.size();
        int tank = 0;
        
        j = 1;
        for (i = start_index; ; i = (i+1) % n, j++)
        {
            tank += gas[i];
            
            //printf("\nIndex = %d Tank : %d Cost : %d ", i, tank, cost[i]);
            
            if (tank < cost[i]) return -1; // indicates FAILURE
            
            tank -= cost[i];
            
            
            
            if (j > n) //break; // This will indicate that we have reached the point where we have started 
                return i; // 1 indicates success
        }
        
        return i;
    }
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // Let's start with O(N^2) runtime algorithm which is also a brute force method.
        // Will start from 1 and see if I can reach 1 or not
        // if I can reach to 1 then we have solution and return 1
        // Otherwise, start from station 2 and keep doing until you find solution
        // If there is no solution then runtime would be O(N^2)
        
        int i, n = cost.size();
        
        for (i = 0; i < n; i++)
        {
            //printf("\n Trying with Index = %d ", i);
            int ret = check(gas, cost, i);
            if (ret >= 0) return ret; 
        }
        
        return -1;
    }
};


/*
31 / 31 test cases passed.
Status: Accepted
Runtime: 240 ms
Memory Usage: 10 MB
Submitted: 0 minutes ago



*/


/// Adding Optimal Solution for this problem 
// runtime would be O(N) whenre N is length of th array

class Solution {  
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // Optimal solution for this problem with runtime O(N)
        // Concept: sum(diff(gas[i], cost[i])) < 0 then there is no solution
        // otherwise there is a solution, lets find the start index
        
        // Scan from 0 index and at any time if the tank goes < 0 then reset the index with next one and 
        // rest tank val to 0
        
        int i, n = cost.size();
        int sum = 0;
        
        
        for (i = 0; i < n; i++) sum += (gas[i] - cost[i]);
        
        if (sum < 0) return -1; // Indicates that there wont be a possible solution
        
        // when we reach here - Solution exists, lets find the starting index
        
        int tank = 0;
        int start_index = 0;
        
        for (i = 0; i < n; i++)
        {
            tank += (gas[i] - cost[i]);
            
            if (tank < 0) // This is very important for this optimal solution
            {
                start_index = i + 1;
                tank = 0;
            }
        }
        
        // Simply return start index which was already saved in our single pass.
        
        return start_index;
    }
};
