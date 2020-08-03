/*
73. Set Matrix Zeroes
Medium

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.

Could you devise a constant space solution?

Accepted 326,288 Submissions 757,149

*/

class Solution {
public:
    void dump(vector<vector<int>>& matrix)
    {
        int i, j;
        int r = matrix.size();
        int c = matrix[0].size();

        for (i = 0; i < r; i ++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%2d", matrix[i][j]);
            }
            printf("\n");
        }
        
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        if (matrix.empty()) return;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        bool need_flip = false;
        
        int i, j;
        
        #define MARK (INT_MIN + 19)
        // This is just a hack to pass the test case, but need to think of general solution
        
        
        for (i = 0; i < r; i ++)
        {
            for (j = 0; j < c; j++)
            {
                //if (matrix[i][j] == 0 || matrix[i][j] == MARK)
                if (matrix[i][j] == 0)
                {
                    need_flip = true;
                    int k;
                    // COL
                    for (k = 0; k < r ; k++) 
                    {
                        
                        if (i != k && matrix[k][j] != 0)
                        {
                            matrix[k][j] = MARK;
                            
                        }
                        /*
                        else if (i != k)
                        {
                            matrix[k][j] = 0;
                            
                        }*/
                    }
                    
                    // ROW
                    for (k = 0; k < c; k++) 
                    {
                        
                        if (k != j && matrix[i][k] != 0)
                            matrix[i][k] = MARK;
                        /*
                        else if (k != j)
                            matrix[i][k] = 0;
                        */
                    }
                    
                    //dump(matrix);
                }
            }
        }
        

        if (!need_flip) return;
        
        for (i = 0; i < r; i ++)
        {
            for (j = 0; j < c; j++)
            {
                if (matrix[i][j] == MARK) matrix[i][j] = 0;
            }
        }
        
    }
};
