/*
566. Reshape the Matrix
Easy

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.

*/


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int ir = nums.size();
        int ic = nums[0].size();
        
        if (r * c != ir * ic) return nums;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        int i, j;
        
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                int t, k, l;
                t = (i) * c + j; // ROW              
                k = t / ic;
                l = t % ic;
                //printf(" T(%d, %d) = S(%d, %d)\n", i, j, k, l);
                res[i][j] = nums[k][l];
            }
        }
        
        return res;
    }
};

/*
Success
Details 
Runtime: 24 ms, faster than 80.62% of C++ online submissions for Reshape the Matrix.
Memory Usage: 11.2 MB, less than 87.69% of C++ online submissions for Reshape the Matrix.


*/
