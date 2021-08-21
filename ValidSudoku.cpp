/*
Valid Sudoku

Solution
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.


*/

class Solution {
public:
    
    // sr = starting row
    // sc = starting col
    bool __check(vector<vector<char>>& board, int r, int c, int sr, int sc, int maxr, int maxc) {
        int i, j;
        
        vector<int> gres(9,0);
        int ii, jj;
        
        // cout << "In Func 1" << "(" << r << ", " << c << ") (" << sr << ", " << sc << ")" <<endl;
        // 1. Check each row with non-repeative digits
        for (i = sr, ii = 0; i < r && ii < maxr; i++, ii++) {
            vector<int> res(9,0); // Initializing vector of 9 with zeros
            for (j = sc, jj = 0; j < c && jj < maxc ; j++, jj++) {
                if (board[i][j] == '.') continue;
                int curr = board[i][j] - '0';
                //cout << endl << "Col = " << j << " Curr = " << curr;
                if (curr < 1 || curr > 9) return false;
                
                if (res[curr - 1]) return false;
                else  if (curr >= 1 && curr <= 9) res[curr - 1] = 1;
                
                if (maxr < 9) {
                    if (gres[curr - 1]) return false;
                    else  if (curr >= 1 && curr <= 9) gres[curr - 1] = 1;
                }
            }
            // cout << endl << "Row = " << i;
        }
        
        // cout << endl << "In Func 2" << endl;
        // 2. Check each col with non-repeative digits
        for (j = sc, jj = 0; j < c && jj < maxc; j++, maxc--) {
            vector<int> res(9, 0); // Initializing vector of 9 with zeros
            for (i = sr, ii = 0; i < r && ii < maxr; i++, ii++) {
                
                int curr = board[i][j] - '0';
                // cout << endl << "ROW = " << i << " Curr = " << curr;
                if (board[i][j] == '.') continue;
                if (curr < 1 || curr > 9) return false;
                
                if (res[curr - 1]) return false;
                else if (curr >= 1 && curr <= 9) res[curr - 1] = 1;
            }
            // cout << endl << "Col = " << j;
        }
        
        //cout << "In Func 3" << endl;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Assuming board size 9X9
        
        // Check each row has non repeative number from 1 to 9
        // Check each col has non repeative number from 1 to 9
        // Check in the 9 grids of size 3X3 for non-repetative digits

        // cout << "0,";
        // Rows and cols
        if (!__check(board, 9, 9, 0, 0, 9, 9)) return false;
        
        // cout << "1,";
        
        // Now work on each 3X3 grid one at a time in a loop
        
       
        int i, j;
        for (i = 0 ; i < 3; i ++)
        {
            for (j = 0; j < 3; j++)
            {
                if (!__check(board, 9, 9, i*3, j*3, 3, 3)) return false;   
            }
        }
        
        return true;
        
        #if 0
        // This is the non-loop case
        // First row grid 1
        if (!__check(board, 9, 9, 0, 0, 3, 3)) return false;
        // First row grid 2
        if (!__check(board, 9, 9, 0, 3, 3, 3)) return false;
        // First row grid 3
        if (!__check(board, 9, 9, 0, 6, 3, 3)) return false;
        
        // cout << "2,";
        
        // Second row grid 1
        if (!__check(board, 9, 9, 3, 0, 3, 3)) return false;
        // second row grid 2
        if (!__check(board, 9, 9, 3, 3, 3, 3)) return false;
        // second row grid 3
        if (!__check(board, 9, 9, 3, 6, 3, 3)) return false;
        
            
        // cout << "3,";
        // Third row grid 1
        if (!__check(board, 9, 9, 6, 0, 3, 3)) return false;
        // Third row grid 2
        if (!__check(board, 9, 9, 6, 3, 3, 3)) return false;
        // Third row grid 3
        if (!__check(board, 9, 9, 6, 6, 3, 3)) return false;
     
        return true;
        #endif
        
        
        
    }
};

/*
507 / 507 test cases passed.
Status: Accepted
Runtime: 20 ms
Memory Usage: 19.8 MB
Submitted: 0 minutes ago


*/
