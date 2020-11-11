/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
 

Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
 

*/


class Solution {
public:
    
    // Geomtry formual to compute distance or length of the line when given two points
    int compute_dist(vector<int> p1, vector<int> p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        // Theory: Compute all possible distances in the square
        // 4 sides and 2 diagnoals --- 6 possible distances
        // For square - ALL four sides whould be same in length and two diagnols should be same in len as well
        // To find this - maintain a set and insert each len into it.
        // Remember - Set will contains only unique elements
        
        // To decide whether it is square or not
        // set should be containing only 2 elements and neither of them should not be '0'
        
        int i;
        
        set<int> s;
        
        s.insert(compute_dist(p1, p2));
        s.insert(compute_dist(p1, p3));
        s.insert(compute_dist(p1, p4));
        s.insert(compute_dist(p2, p3));
        s.insert(compute_dist(p2, p4));
        s.insert(compute_dist(p3, p4));
        
        return (s.find(0) == s.end()) && s.size() == 2;
        
        /*
        244 / 244 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 26.5 MB
Submitted: 0 minutes ago
        */
    }
};
