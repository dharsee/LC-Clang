/*
Sudoku Solver

Solution
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.



NOTE: Followed below link

https://www.tutorialspoint.com/Sudoku-Solving-algorithms


*/


class Solution {
    
    vector<vector<char>> board;
public:
    
    // Check given num is present in the given column.
    bool isPresentInCol(int col, int num) {
        int i, r;
        
        r = board.size();
        
        for (i = 0; i < r; i++)
            if (board[i][col] == '0' + num) return true;
        
        return false;
    }
    
    // Check given num is present in the given Row.
    bool isPresentInRow(int row, int num) {
        int j, c;
        
        c = board[0].size();
        
        for (j = 0; j < c; j++)
            if (board[row][j] == '0' + num) return true;
        
        return false;
    }
   
    
    bool isPresentInBox(int startRow, int startCol, int num) {
        int i, j, r, c;
        
        r = board.size();
        c = board[0].size();
        
        for (i = startRow; i < startRow + 3; i++) {
            for (j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == '0' + num) return true;
            }
        }
        return false;
    }
    
    void printSudokuGrid() {
        int i, j, r, c;
        
        r = board.size();
        c = board[0].size();
        
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (j == 3 || j == 6) 
                    cout << " | ";
                cout << board[i][j] << " ";
            }
            
            if (i == 2 || i == 5) {
                cout << endl;
                for (int k = 0; k < r; k++) {
                    cout << "---";
                }
            }
            cout << endl;
        }
    }
    
    
    bool findEmptyPlace(int &row, int &col) {
        int i, j, r, c;
        
        r = board.size();
        c = board[0].size();
        
        for (row = 0; row < r; row++) {
            for (col = 0; col < c; col++) {
                if (board[row][col] == '.' ) return true;
            }
        }
        
        return false;
    }
    
    bool isValidPlace(int &row, int &col, int num) {
        
        return !isPresentInRow(row, num) &&
                !isPresentInCol(col, num) &&
                !isPresentInBox(row - row % 3, col - col % 3, num);
    }
    
    
    bool __solveSudoku() {
        int row, col;
        
        if (!findEmptyPlace(row, col)) return true;
        
        for (int num = 1; num <= 9; num++) {
            if (isValidPlace(row, col, num)) {
                board[row][col] = num + '0';
                if (__solveSudoku()) return true;
                
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    
   
    
    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        
        /*
        // For DEBUG 
        if (__solveSudoku() == true) printSudokuGrid();
        else cout << "\n\n No Solution Exists!";
        */
        __solveSudoku();
        board = this->board;
    }
};


/*
6 / 6 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 6.6 MB
Submitted: 0 minutes ago




*/
