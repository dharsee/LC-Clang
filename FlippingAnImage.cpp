/*
Flipping an Image

Solution
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

*/

class Solution {
public:
    
    // Invert Binary Array
    inline void invert(vector<int> &A)
    {
        int n = A.size();
        if (n == 0) return;
        
        int i;
        
        for (i = 0; i < n; i++)
        {
            A[i] = A[i] == 1 ? 0 : 1;
        }
    }
    
    // Reverse Binary array
    inline void reverse(vector<int> &A)
    {
        int n = A.size();
        
        if (n == 0) return;
        int i, j;
        
        i = 0; 
        j = n - 1;
        
        while (i < j)
        {
            if (A[i] != A[j])
            {
                A[i] = !A[i];
                A[j] = !A[j];
            }
            
            ++i;
            --j;
        }
    }
    
    // Integrating Flip and Invert in the single function
    inline void reverse_and_invert(vector<int> &A)
    {
        int n = A.size();
        
        if (n == 0) return;
        int i, j;
        
        reverse(A);
        invert(A);
        
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        int r = A.size();
        if (r == 0) return {{}};
        
        int i = 0;
        int j = r - 1;
        while(i < j)
        {
            reverse_and_invert(A[i]);
            reverse_and_invert(A[j]);
 
            i++;
            --j;
        }
        if (i == j)
            reverse_and_invert(A[j]);
        
        return A;
        
    }
  
};
