/*

Rotting Oranges

Solution
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.

*/

class Solution {
public:
    
    void dump(vector<vector<int>>& grid)
    {
        int i, j;
        int r = grid.size();
        int c = grid[0].size();
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%3d", grid[i][j]);
            }
            printf("\n");
        }
    }
    
    


    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        if (!r || !c) return 0;
        //if (!fresh_exists(grid)) return 0;
        
        int i, j, count = 0;
        
        /*
        printf("\n Beginning \n");
        dump(grid);
        */
        
        
        queue<pair<int, int>> q;
        int fresh_count = 0;
        
        // Add ALL rotten orange location to the queue
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i,j}); 
                else if (grid[i][j] == 1)
                    fresh_count++;
            }
        }
        
        //printf(" \n Fresh count = %d count = %d ", fresh_count, count);
        
        // PROCESS Q
        
        while (!q.empty())
        {
            // POP all q elements and see if there are any fresh neighbors to each, push back if exists
            int qsz = q.size();
            
            for (int qi = 0; qi < qsz; qi++)
            {
                pair<int, int> p = q.front();
                q.pop();
            
                i = p.first;
                j = p.second;
                
                //printf("\nprocessing location (%d, %d), Fcount = %d , count = %d, r %d c = %d ", i, j, fresh_count, count, r, c);
                // Now check 4 directions for this rotten orange
                
                if (i > 0 && grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                    fresh_count--;
                    q.push({i-1, j});
                }
               
                if (i < r - 1 && grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                    fresh_count--;
                    q.push({i+1, j});
                }
                
                if (j > 0 && grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    fresh_count--;
                    q.push({i, j-1});
                }
               
                if (j < c - 1 && grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    fresh_count--;
                    q.push({i, j+1});
                }
            } //End of for loop
            
            if (!q.empty()) count++;
        } // While loop
        
        
        //printf(" Fresh count = %d count = %d ", fresh_count, count);
        if (fresh_count == 0) return count;
        else return -1;
        
        
    }
};
