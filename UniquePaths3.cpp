/*
Unique Paths III

Solution
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20

*/

class Solution {
    
    void explore(vector<vector<int>> &grid, int i, int j, int r, int c, int &count, int zcount, int curr_count)
    {
        //printf("\nExplore (%d, %d) ", i, j);
        // Out of boundary check
        if (i < 0 || i > r || j < 0 || j > c) return;
        
        // Target met
        if (grid[i][j] == 2)
        {
            //printf("\nExplore 2(%d, %d) -- zcount = %d curr_count = %d count = %d ",
            //       i, j, zcount, curr_count, count);
            
            // Here we need to check with curr_count - 1, it plays very important role
            if (zcount == curr_count - 1) count++;
            return;
        }
        
        // Obstacles we cannot walk on this grid
        if (grid[i][j] == -1) return;
        
        // Set by us to indicate that it is already visisted in this current path
        if (grid[i][j] == 4) return;
        
        // convert current grid to other numerical val or set it to -1, to indicate visited
        grid[i][j] = 4;
        
        // UP
        if (i > 0) explore(grid, i - 1, j, r, c, count, zcount, curr_count + 1);
        
        
        // DOWN
        if (i < r - 1) explore(grid, i + 1, j, r, c, count, zcount, curr_count + 1);
        
        
        // LEFT
        if (j > 0) explore(grid, i, j - 1, r, c, count, zcount, curr_count + 1);
        
        // RIGHT
        if (j < c - 1) explore(grid, i, j + 1, r, c, count, zcount, curr_count + 1);
        
        // revert it back; BACKTRACKING, this is also very important step in this algorithm
        grid[i][j] = 0;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        
        int count = 0, i, j, k, zcount = 0;
        int r = grid.size(), c = grid[0].size();
        
        // Count number of zeros are present on the grid
        // This count is imporatnt to qualify path has covered all zeros or not when we reach to target
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    zcount++;
                    //printf("\n (%d, %d) = %d ", i, j, zcount);
                }
            }
        }
        //printf("\n Zcount = %d ", zcount);
        
        int curr_count = 0;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    explore(grid, i, j, r, c, count, zcount, curr_count);
                }
            }
        }

        return count;
    }
};


/*

39 / 39 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 7.3 MB
Submitted: 0 minutes ago



*/
