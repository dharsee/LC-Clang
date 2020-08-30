/*
Largest Component Size by Common Factor

Solution
Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000

*/

class Solution {
public:

    /*
      Lets Solve this problem by using Disjoint set datastructure 
      1. Build disjoint unions
      2. find and union operations
    */


    int _find(vector<int> &parent, int x)
    {
        if (parent[x] == -1) return x;

        parent[x] = _find(parent, parent[x]);
        return parent[x];
    }

    void _union(int a, int b, vector<int> &parent)
    {
        int aparent = _find(parent, a);
        int bparent = _find(parent, b);

        if (aparent != bparent)
        {
            parent[bparent] = aparent;
        }
    }

    int largestComponentSize(vector<int> &A){

        vector<int> parent(100001, -1); // all possible values

        for (int a : A)
        {
            for (int i = 2; i <= sqrt(a); i++)
            {
                if (a % i == 0)
                {
                    _union(i, a, parent);
                    _union(a, a/i, parent);
                }
            }
        }

        // Maintain unordered map to maintain count for each parent group
        int res = 0;
        
        unordered_map<int, int> hmap;

        for(int a: A)
        {
            int aparent = _find(parent, a);
            res = max(res, 1 + hmap[aparent]);
            hmap[aparent] =  hmap[aparent] + 1;
        }
        
        return res;
    }
};
