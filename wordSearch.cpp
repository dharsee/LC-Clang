/*
79. Word Search
Medium

Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

class Solution {
public:
    
    
    
    bool check(vector<vector<char>>& board, int r, int c, int i, int j, 
               string &word, int indx)
    {
        
        // return true when we reach end of word
        if (indx == word.length() - 1) return true;
        
        // MArk this grid as visited
        board[i][j] -= 65;
        
        // UP
        if (i > 0)
        {
            if (board[i-1][j] == word[indx+1])
                if (check(board, r, c, i - 1, j, word, indx + 1)) return true;
        }
        
        // DOWN
        if (i < r - 1)
        {
            if (board[i+1][j] == word[indx+1])
                if (check(board, r, c, i + 1, j, word, indx + 1)) return true;
        }
        
        // LEFT
        if (j > 0)
        {
            if (board[i][j-1] == word[indx+1])
                if (check(board, r, c, i, j-1, word, indx + 1)) return true;
        }
        
        // RIGHT
        if (j < c - 1)
        {
            if (board[i][j+1] == word[indx+1])
                if (check(board, r, c, i, j+1, word, indx + 1)) return true;
        }
        
        board[i][j] += 65;
        
        
        return false;
        
    }
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
   
        int r = board.size();
        int c = board[0].size();
        
        // No visited grid just flip the current element to out of order then bring it back to original
        
        int i, j;
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (board[i][j] == word[0]) //first call to DFS
                    if(check(board, r, c, i, j, word, 0)) return true;
                // otherwise try for other grids
            }
        }
        
        
        return false;
    }
    
    
    
    // Similar to above solution but using visited array which will take O(RXC) space
    
    #if 0
    
    bool check(vector<vector<char>>& board, int r, int c, int i, int j, 
               string &word, int indx, vector<vector<bool>> &visited)
    {
        
        // return true when we reach end of word
        if (indx == word.length() - 1) return true;
        
        // MArk this grid as visited
        visited[i][j] = true;
        
        // UP
        if (i > 0)
        {
            if (!visited[i-1][j] && board[i-1][j] == word[indx+1])
                if (check(board, r, c, i - 1, j, word, indx + 1, visited)) return true;
        }
        
        // DOWN
        if (i < r - 1)
        {
            if (!visited[i+1][j] && board[i+1][j] == word[indx+1])
                if (check(board, r, c, i + 1, j, word, indx + 1, visited)) return true;
        }
        
        // LEFT
        if (j > 0)
        {
            if (!visited[i][j-1] && board[i][j-1] == word[indx+1])
                if (check(board, r, c, i, j-1, word, indx + 1, visited)) return true;
        }
        
        // RIGHT
        if (j < c - 1)
        {
            if (!visited[i][j+1] && board[i][j+1] == word[indx+1])
                if (check(board, r, c, i, j+1, word, indx + 1, visited)) return true;
        }
        
        visited[i][j] = false;
        
        
        return false;
        
    }
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
   
        int r = board.size();
        int c = board[0].size();
        
        //maintained visited grid to avoid loop
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        int i, j;
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (board[i][j] == word[0]) //first call to DFS
                    if(check(board, r, c, i, j, word, 0, visited)) return true;
                // otherwise try for other grids
            }
        }
        
        
        return false;
    }
    
    #endif
    
    
};
