/*
Task Scheduler

You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tsz = tasks.size();
        if (n == 0 || tasks.empty()) return tsz;
        
        // Build frequency table
        
        int i = 0;
        unordered_map <int, int> hmap;
        
        for (i = 0; i < tsz; i++)
            hmap[tasks[i]]++;
        
        // Maintaint priority queue to hold max heap
        // will store only frequency of the task
        
        priority_queue<int> pq;
        
        // Build PQ
        for (auto m : hmap)
            pq.push(m.second); // keeping only frequency
        
        
        // Now loop through PQ and build the schedule of len n+1 at a time
        
        int res = 0;
        while(!pq.empty())
        {
            int lapse = 0;
            vector<int> temp; //to restore current value to PQ
            
            int k = 0;
            for(; k < n + 1; k++)
            {
                if (!pq.empty())
                {
                    temp.push_back(pq.top() - 1); // one of the task is execute now, add rest to the PQ
                    pq.pop();
                    lapse++;
                }
            }
            
            // Push back to PQ
            for (auto t : temp)
                if (t > 0) pq.push(t);
            
            res += pq.empty() ? lapse : n + 1; /// it will take care of partial cycle len
        }
        
        return res;
        
    }
};
