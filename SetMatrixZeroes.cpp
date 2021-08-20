/*
Set Matrix Zeroes

Solution
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/



class Solution {
public:
    void printMatrix(vector<vector<int>>& matrix) {
        int i, j;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << matrix[i][j] << "  ";
            }
            cout << endl ;
        }
        
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        // vector<vector<int>>& matrix
        // 2 pass algorithm
        // in first pass - identify all the rows and coloumns which would need to
        // mark as 0's and place a flag in their correpsonding row and col
        
        // in second pass: Flip/mark as zeros as per row/col's first val
        
        // Pass - 1
        int i, j;
        bool flipped = false;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        bool first_row = false, first_col = false;
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0) {
                    if (i == 0) first_row = true;
                    if (j == 0) first_col = true;
                
                
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        /*
        cout << endl << "After setting first row/col with zero " << endl;
        printMatrix(matrix);
        
        cout << endl << "First Row = " << first_row << " First Col = " << first_col << endl;
        */
        // Pass - 2
        
        // For each row
        for (i = 1; i < r; i++)
        {
            
            if (matrix[i][0] == 0) {
                for (j = 1; j < c; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        /*
        cout<< endl << "After Row zeros \n";
        // After row zeros
        printMatrix(matrix);
        */
        // For each Col
        for (j = 1; j < c; j++)
        {
            if (matrix[0][j] == 0)
            {
                // mark while row with zero
                for (i = 1; i < r; i++) {
                        matrix[i][j] = 0;
                }
            }
        }
        
        /*
        cout<< endl << "After Col zeros \n";
        // After row zeros
        printMatrix(matrix);
        
        */
        // Now work for first row and first col
        
        if (first_row) {
            for (j = 0; j < c; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (first_col) {
            for (i = 0; i < r; i++)
            {
                matrix[i][0] = 0;
            }
        }       
    }
};


/*
164 / 164 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 13.2 MB
Submitted: 1 minute ago


*/
