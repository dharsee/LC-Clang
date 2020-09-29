/*
Evaluate Division

Solution
You are given equations in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating-point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= equations[i][0], equations[i][1] <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= queries[i][0], queries[i][1] <= 5
equations[i][0], equations[i][1], queries[i][0], queries[i][1] consist of lower case English letters and digits.
   Hide Hint #1  
Do you recognize this as a graph problem?

*/


class Solution {
public:
    // This is DAG - Directed Acycle Graph problem
    // Build the DAG, a/b means a to b and we need to add reverse vertex b to a with 1/its val
    // run DFS search from source to destination node
    // if then nodes are not part of the graph then result should be -1.0
    // 
    
    // DEBUG Purpose
    void dump(vector<pair<string, double>> &curr)
    {
        printf("\n ROW ----> : ");
        int i, n = curr.size();
        
        for (i = 0; i < n; i++)
            cout << ", " << curr[i].first;
        
        printf("\n");
    }
    
    // DEBUG purpose
    void dump_hmap(map<string, vector<pair<string, double>>> &hmap)
    {
        int i, n = hmap.size();
        
        auto iter = hmap.begin();
        
        while (iter != hmap.end())
        {
            cout << endl << " NODE : " << iter->first << "  -- > ";
            int j = 0, n1 = iter->second.size();
            for (j = 0; j < n1; j++)
                cout << "<" << iter->second[j].first << ", " << iter->second[j].second << ">, ";
            
            iter++;
        }
    }
    
    
    
    double dfs(map<string, vector<pair<string, double>>> &hmap, 
                       string src, string dest, set<string> visited)
    {
        //cout << " dfs ....src " << src << " Dest " << dest << endl;
        // either of src or dest is does not exist then return -1.0
        if (hmap.find(src) == hmap.end() || hmap.find(dest) == hmap.end())
            return -1.0;
        
        // When we found dest, return 1.0
        if (src == dest) return 1.0;
        
        // Mark this  node as visited to avoid infinite loop
        visited.insert(src);
        
        // Do dfs for all nodes connected to it one by one
        int i = 0;
        vector<pair<string, double>> curr;
        
        curr = hmap[src];
        //dump(curr);
        int n = curr.size();
        for (i = 0; i < n; i++)
        {
            // If this node is already marked as VISITED then dont invoke dfs()
            if (visited.find(curr[i].first) == visited.end()) // not visited yet
            {
                double ans = dfs(hmap, curr[i].first, dest, visited);
                if (ans != -1.0)
                {
                    return ans * curr[i].second;
                }
            }
        }
        
        return -1.0;
    }
    
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, vector<vector<string>>& queries) {
        
        // BUILD DAG by reading input equation, each term  in equation will be treated as node
        // its values will be the cost/weight of the edge b/w these two nodes
        
        // main a map<string, vector<pair<string, double>>>
        // This also indicates adjacent matrix of the graph
        map<string, vector<pair<string, double>>> hmap;
        
        int i = 0, n = equations.size(); 
        for (i = 0; i < n; i++)
        {
            string src = equations[i][0];
            string dest = equations[i][1];
            
            hmap[src].push_back({dest, values[i]});
            hmap[dest].push_back({src, 1/values[i]});
            //second line indicates that when a/b = 2; then b/a should be 1/2
        }

        /*
        printf("\n**** BEGIN HMAP ....");
        dump_hmap(hmap);
        printf("\n**** END HMAP .... \n");
        */
        
        // Now scan each query and run the DFS to find the dest in the graph
        n = queries.size();
        vector<double> res(n, 0.0);
        
        for (i = 0; i < n; i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];
            
            set<string> visited;
            res[i] = dfs(hmap, src, dest, visited);
        }
        
       return res; 
        
    }
    
    /*
    22 / 22 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 8.6 MB
Submitted: 0 minutes ago

    
    */
    
};
