/*
Search a 2D Matrix

Solution
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

class Solution {
public:
    
    inline int bin_search(vector<vector<int>>& matrix, int row, int target)
    {
        int cols = matrix[row].size();
        
        int l = 0, h = cols - 1, mid = 0;
        
        while (l <= h)
        {
            mid = (h - l) / 2 + l;
            
            if (matrix[row][mid] == target) return mid;
            else if (matrix[row][mid] > target) h = mid - 1;
            else l = mid + 1;
        }
        
        return -1;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        
        if (m == 0) return false;
        
        int n = matrix[0].size();
        
        if (n == 0) return false;
        
        
        int i;
        
        // Do a binary search for the row which has the range to determin element is present or not
        for (i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n-1])
            {
                //should be in this range or else we can declare element is not present
                
                int ret = bin_search(matrix, i, target);
                if (ret >= 0) return true;
                else return false;
            }
        }
        
        return false;
        
        /*        
            135 / 135 test cases passed.
            Status: Accepted
            Runtime: 4 ms
            Memory Usage: 9.9 MB
            Submitted: 0 minutes ago
        */
        
    }
};
