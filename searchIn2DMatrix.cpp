/*
74. Search a 2D Matrix
Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

*/

class Solution {
public:
    
    bool bin_search(vector<int> &arr, int l, int h, int target)
    {
        int mid = 0;
        
        while (l <= h)
        {
            mid = l + ((h -l) / 2);
            
            if (arr[mid] == target) return true;
            else if (arr[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty()) return false;
        
        int r = matrix.size();
        int c = matrix[0].size();
        int i, j;
        
        if (r == 0 || c == 0) return false; // This is to avoid null matrix
        
        // Out of range condition, since matrix has special property
        if (target < matrix[0][0] || target > matrix[r-1][c-1]) return false;
        
        for (i = 0; i < r; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][c-1])
            {
                return bin_search(matrix[i], 0, c, target);
            }
        }
        
        return false;
        
    }
};
