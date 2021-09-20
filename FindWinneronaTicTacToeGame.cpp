/*

Find Winner on a Tic Tac Toe Game

Solution
Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player A always places "X" characters, while the second player B always places "O" characters.
"X" and "O" characters are always placed into empty squares, never on filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.

 

Example 1:

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"
Example 2:

Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
"   "    "   "    "   "    "   "    "   "    "O  "
Example 3:

Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
"XXO"
"OOX"
"XOX"
Example 4:

Input: moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
"X  "
" O "
"   "
 

Constraints:

1 <= moves.length <= 9
moves[i].length == 2
0 <= moves[i][j] <= 2
There are no repeated elements on moves.
moves follow the rules of tic tac toe.

*/

class Solution {
public:
    
    void printG(vector<vector<int>> &g){
        
        int r = g.size();
        int c = g[0].size();
        
        int i, j;
        
        cout << endl << "Filled Grid 3x3 : " << endl;
        
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                cout << g[i][j] << "    ";
            }
            cout << endl;
        }
        
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        
        int n = moves.size();
        
        if (n <= 4) return "Pending"; // Game has not finished.
        
        vector<vector<int>> grid;
        // 1 defines 'X' and player 'A'
        // 0 defines 'O' and player 'B'
        // -1 defines empty cell
        
        // Initialize
        for (int i = 0; i < 3; i++) {
            vector<int> temp(3, -1);
            grid.push_back(temp);
        }
        
        // Now start reading input moves and fill the grid, after filling 9 or less moves ... check for result.
        
        int i;
        
        for (i = 0; i < n; i++)
        {
            int r = moves[i][0];
            int c = moves[i][1];
            if (r > 2 || r < 0 || c > 2 || c < 0) return "Wrong Input values";
                
            if (i % 2 == 1) { // Player 'A'    
                grid[r][c] = 0;
            } else { // Player 'B'
                grid[r][c] = 1;
            }
        }
        
        /*
        printG(grid);
        
        cout << endl << "Done with filling";
        */
        // Now check for result
        int j = 0;
        i = 0;
        
        // Look for rows
        for (i = 0; i < 3; i++) {
            j = 1;
            if (grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i][j+1]) {
                if (grid[i][j] == 1) return "A";
                else if (grid[i][j] == 0) return "B";
            }
        }
        
        // cout << endl << "Done scanning ROWS";
        
        // Look for Cols
        for (j = 0; j < 3; j++) {
            cout << endl << " Col .. j = " << j;
            i = 1;
            if (grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i+1][j]) {
                if (grid[i][j] == 1) return "A";
                else if (grid[i][j] == 0) return "B";
            }
        }
        
        // cout << endl << "Done scanning COLS";
        
        // Look for diagnol\
        
        i = 1;
        j = 1;
        
        if (grid[i][j] == grid[i-1][j-1] && grid[i][j] == grid[i+1][j+1]) {
                if (grid[j][i] == 1) return "A";
                else if (grid[j][i] == 0) return "B";
        }
        
        if (grid[i][j] == grid[i+1][j-1] && grid[i][j] == grid[i-1][j+1]) {
                if (grid[j][i] == 1) return "A";
                else if (grid[j][i] == 0) return "B";
        }
        // cout << endl << "Done scanning DIAGNOL .. and will return DRAW";
        
        if (n < 9) return "Pending";
        return "Draw";
    }
};

/*
100 / 100 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 8.3 MB
Submitted: 0 minutes ago


*/
