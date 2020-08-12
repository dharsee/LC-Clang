/*
Pascal's Triangle II

Solution
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    
    void dump(vector<vector<int>> &res)
    {
        int r = res.size();
        //int c = res[0].size();
        int i, j;
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < res[i].size(); j++)
            {
                printf(" %3d", res[i][j]);
            }
            printf("\n");
        }
        
    }
    
    
    // Optimized solution
    
    /*
        We know that this solution is cosuming more space 
        we can optimize space complexity
        All we need to construct current row is that previous row only.
        If we can maintain previous row and that would be great optimization to the space complexity
    */
    
    vector<int> getRow(int rowIndex) {
        
        // rowIndex starts from zero
        if (rowIndex < 0) return vector<int>{};
        
        int i, j, k, m, n;
        
        vector<vector<int>> res; // Consuming more space here by keeping old entries in the array
        vector<int> prev, curr;
        
        
        // Build first two rows out of loop
        prev.push_back(1); // R1
        if (rowIndex == 0) return prev;
        
        // Build second row, index 1
        prev.push_back(1);
        if (rowIndex == 1) return prev;
        
        //intialize curr with single element
        curr.push_back(1);
        
        // contrusct loop for higher indices       
        for (i = 2; i <= rowIndex; i++)
        {
            if ((i & 0x1) == 0) // Even cycle
            {
                // use prev to construct curr
                // First element is already present
                for (j = 1; j < i; j++)
                {
                    if (curr.size() <= j)
                        curr.push_back(prev[j-1] + prev[j]);
                    else
                        curr[j] = prev[j-1] + prev[j];
                }
                
                // Add last item to curr
                curr.push_back(1);    
                
            }
            else
            {
                // Use curr to build prev
                // First element is already present
                for (j = 1; j < i; j++)
                {
                    if (prev.size() <= j)
                        prev.push_back(curr[j-1] + curr[j]);
                    else
                        prev[j] = curr[j-1] + curr[j];
                }
                
                // Add last item to curr
                prev.push_back(1); 
            }
            
        }
        
        if (rowIndex & 0x1) // ODD?
            return prev;
        else
            return curr;
    }
    
    
    /* Naive solution, uses more space complexity, O(sum(k)) */
    vector<int> getRow_2(int rowIndex) {
        
        // rowIndex starts from zero
        if (rowIndex < 0) return vector<int>{};
        
        int i, j, k, m, n;
        
        vector<vector<int>> res; // Consuming more space here by keeping old entries in the array
        
        
        // Build first two rows out of loop
        res.push_back(vector<int>{1}); // R1
        
        res.push_back(vector<int>{1}); //R2
        res[1].push_back(1);
        
        //dump(res);
        
        // contrusct loop for higher indices       
        for (i = 2; i <= rowIndex; i++)
        {
            res.push_back(vector<int>{1});
            
            for (j = 1; j < i; j++)
            {
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res[i].push_back(1);
        }
        
        //dump(res);
        
        return res[rowIndex];
        
        // We know that this solution is cosuming more space 
        // we can optimize space complexity
        // All we need to construct current row is that previous row only.
        // If we can maintain previous row and that would be great optimization to the space complexity
        
        
    }
};
