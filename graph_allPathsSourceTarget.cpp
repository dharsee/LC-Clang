
/*
All Paths From Source to Target

Solution
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

class Solution {
public:
    
    
    void dfs(vector<vector<int>>& graph, int node,
            vector<int> curr, vector<vector<int>> &gres) {
        
        int n = graph[node].size();
        
        curr.push_back(node);
        
        /*
        printf("\n n = %d Current : ", n);
        int j = 0;
        while(j < curr.size())
        {
            printf(" %d ->", curr[j]);
            j++;
        }
        */
        
        if (n == 0) 
        {
            // WE have reached to the end
            // Now see if that is a target or not
            // IF this node is target then add current path to the result path
            // otherwise, go back without adding to the list;
            
            if (node == graph.size() - 1) // we hit the target node and end
            {
                gres.push_back(curr);
            }
            return;
        }
        
        // Do the same for all of its connected paths
        int i = 0;
        while (i < n)
        {
            
            int k = graph[node][i];
            
            dfs(graph, k, curr, gres);
            i++;
        }
        
    }
        
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // Given input is in the form of adjacent list
        // Traverse adjacent list of the graph to go to the end.
        // If the path doesnt reach the target then dont add it to the result list
        vector<int> curr;
        int n = graph.size();
        if (n <= 1)
        {
            vector<vector<int>> res;
            if (n == 0) return res;
            else return graph;
        }
        
        // Always start with 0th node and target is the nth node
        
        int i, j;
        
        vector<vector<int>> gres;
        
        n = graph[0].size();
        curr.push_back(0);
        
        for (i = 0; i < n; i++)
        {
            int k = graph[0][i];
            dfs(graph, k, curr, gres);
        }
        
        return gres;
        
    }
};
