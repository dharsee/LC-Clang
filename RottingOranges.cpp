/*

994. Rotting Oranges
Medium

4760

239

Add to List

Share
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/


class Solution {
public:
    
    /*
    void check_dfs(vector<vector<int>>& grid, int i, int j, int &count) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        cout << "(" << i << ", " << j << ")   (" << r << ", " << c << ")" << endl;

        if (i < 0 || j < 0 || i > r || j > c) return;
        
        if (grid[i][j] >= 2) return;
        
        grid[i][j] += 99;
        // RIGHT
        if (i + 1 < r && grid[i+1][j] == 1) 
        {
            count++;
            check_dfs(grid, i+1, j, count);
        }
        
        // LEFT
        if (i > 0 && grid[i-1][j] == 1) {
            count++;
            check_dfs(grid, i-1, j, count);
        }
        
        // UP
        if (j > 0 && grid[i][j-1] == 1) {
            count++;
            check_dfs(grid, i, j-1, count);
        }
        
        // DOWN
        if (j + 1 < c && grid[i][j+1] == 1) {
            count++;
            check_dfs(grid, i, j + 1, count);
        }
        
        grid[i][j] -= 99;
    }
    
    */
    
    /*
    DFS approach is incorrect
    Need to work with BFS and keep counting
    
    1. Maintain Q <row, col> of rotten orange
    2. Count number of fress_oranges
    
    Process Q items one by one and if its neighbor is fress then add it to the Q and 
    decrement the fress_count
    
    Also increment the count to indicates time for making it to fully rotten
    
    At end, if fresh_count remains then not possible which is return -1;
    else return count
    
    
    */
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int count = 0;
        int r = grid.size();
        int c = grid[0].size();
        
        if (r == 0  || c == 0) return 0;
        
        int i, j;
    
        queue<pair<int, int>> q; // It holds row, col of the rotten orange
        
        // First pass, fill rotten oraanges' grid in the q and count fresh_oragens
        int fresh_oranges = 0;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j] == 1) { // Fresh Orange
                    fresh_oranges++;
                } else if (grid[i][j] == 2) { // Rotten 
                    // add it to the queue
                    q.push({i, j});
                }
            }
        }
        
        
        while (!q.empty()) {
            
            // Get the size of the queue
            int qsz = q.size();
            
            for (i = 0; i < qsz; i++) {
                // POP out fron item
                
                int row, col;
                
                pair<int, int> p = q.front();
                q.pop();
                
                row = p.first;
                col = p.second;
                
                // check for its neighbors if any
                // RIGHT
                if (row + 1 < r && grid[row+1][col] == 1) 
                {
                    grid[row+1][col] = 2;
                    fresh_oranges--;
                    q.push({row+1, col});
                }

                // LEFT
                if (row > 0 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    fresh_oranges--;
                    q.push({row-1, col});
                }

                // UP
                if (col > 0 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    fresh_oranges--;
                    q.push({row, col-1});
                }

                // DOWN
                if (col + 1 < c && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    fresh_oranges--;
                    q.push({row, col+1});
                }

                
                
                
                
            } // End of for loop
            
            if (q.empty()) break;
            count++;
            
        }
        
        
        if (fresh_oranges > 0) return -1;
        
        return count;
        
    }
};


/*

Success
Details 
Runtime: 4 ms, faster than 92.11% of C++ online submissions for Rotting Oranges.
Memory Usage: 13.1 MB, less than 50.83% of C++ online submissions for Rotting Oranges.

*/
