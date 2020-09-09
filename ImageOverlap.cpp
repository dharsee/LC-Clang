/*
Image Overlap

Solution
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1

*/

class Solution {
public:
    
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int count = 0;
        int n = A.size(); // Assuming A'size and B'size are same and NxN
        
        int i, j, x, y;
        
        // x and y represent co-ordinates shifts
        // i and j represents row and column
        
        for (x = 0; x < n; x++)
        {
            for (y = 0; y < n; y++)
            {
                int curr_count = 0;
                for (i = y; i < n; i++)
                {
                    for (j = x; j < n; j++)
                    {
                        if (A[i][j] == 1 && B[i-y][j-x] == 1) curr_count++;
                    }
                }
                
                if (curr_count > count) count = curr_count;
            }
        }
        
        return count;
    }
    
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
       int ac = 0, bc = 0;
        
        ac = countOverlap(A, B); // This will cover Right and Down sliding
        bc = countOverlap(B, A); // This will cover Left and UP sliding
        
        return max(ac, bc);
        
        
    }
};
