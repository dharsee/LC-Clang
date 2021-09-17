/*
Spiral Matrix

Solution
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
   Show Hint #1  
   Show Hint #2  
   Hide Hint #3  
Think about when you want to switch the progress on one of the indexes. If you progress on
i
out of
[i, j]
, you'd be shifting in the same column. Similarly, by changing values for
j
, you'd be shifting in the same row. Also, keep track of the end of a boundary so that you can move inwards and then keep repeating. It's always best to run the simulation on edge cases like a single column or a single row to see if anything breaks or not.

*/

class Solution {
public:
    
    void printVec(vector<int> &res) {
        
        auto iter = res.begin();
        cout << endl;
        
        while (iter != res.end()) {
            cout << *iter << ", ";
            iter++;
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int right, left, up, down;
        int r = matrix.size();
        int c = matrix[0].size();
        
        if (r == 1) return matrix[0];
        
        int sz = r * c;
        vector<int> res(sz, 0);
        
        
        int i, j, k, m, p;
        int indx = 0;
        
        // Initial configuration
        right = c;
        left  = 0; //c - 1;
        down  = r;
        up    = 0; //r - 1;
        
        // In each loop, go right, go down, go left, go up until you have something to travel
        for (i = 0; i < down; i++) {
            
            // Go Right
            for (j = i; j < right && indx < sz; j++) {
                res[indx++] = matrix[i][j];
            }
            // Decrement right by 1
            right--;
            
            /*
            cout << "\nPost Right Walk:";
            printVec(res);
            */
            // Go Down, represent row, col would be fixed
            for (m = i+1; m < down && indx < sz; m++) {
                res[indx++] = matrix[m][j-1];
            }
            down--;
            
            /*
            cout << "\nPost Down Walk:";
            printVec(res);
            */
            // Go Left, represent col, in this case row would be fixed
            // cout << endl << "Left = " << left << " right = " << right <<  " down = " << down <<  endl;
            for (k = right - 1; k >= left && indx < sz; k--) {
                // res[indx++] = matrix[m-1][k-1];
                res[indx++] = matrix[down][k];
            }
            left++;
            
            /*
            cout << "\nPost Left Walk:";
            printVec(res);
            */
            
            // Go UP, represent col, in this case col would be fixed
            // cout << endl << "Left = " << left << " Down = " << down <<  " UP = " << up << " K = " << k << endl;
            for (p = down - 1; p > up && indx < sz; p--) {
                res[indx++] = matrix[p][k+1];
                // res[indx++] = matrix[k][p];
            }
            
            up++;
            
            /*
            cout << "\nPost UP Walk:";
            printVec(res);
            
            
            cout << endl;
            
            printVec(res);
            */
        }
        
        
        return res;
        
        
        
    }
};

/*
23 / 23 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 6.9 MB
Submitted: 0 minutes ago


*/
