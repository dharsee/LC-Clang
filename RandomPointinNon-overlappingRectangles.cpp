/*
Random Point in Non-overlapping Rectangles

Solution
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]
Example 2:

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.


*/

class Solution {
    int num_pts = 0;
    vector<vector<int>> rects;
    vector<int> cum_rect;
    
public:
    
    
    Solution(vector<vector<int>>& rects) {
        num_pts = 0;
        this->rects = rects;
        
        for (auto r : rects)
        {
            num_pts += (r[2] - r[0] + 1) *(r[3] - r[1] + 1);
            cum_rect.push_back(num_pts);
        }
        
    }
    
    vector<int> pick() {
        int p_index = rand() % num_pts;
        int l = 0, h = rects.size() - 1;
        
        while (l < h)
        {
            int m = l + (h - l) / 2;
            
            if (cum_rect[m] <= p_index) l = m + 1;
            else h = m;
        }
        
        vector<int> &rect = rects[l];
        
        int x = rect[2] - rect[0] + 1;
        int y = rect[3] - rect[1] + 1;
        
        int p_in_rect = x * y;
        int p_start = cum_rect[l] - p_in_rect;
        int off = p_index - p_start;
        
        return {rect[0] + off%x, rect[1] + off/x};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
