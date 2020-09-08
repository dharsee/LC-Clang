/*
46. Permutations
Medium

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
public:
    
    vector<vector<int>> __permute(vector<int> &v)
    {
        // BASE CASE for recursion
        if (v.size() <= 1) return {v};
        
        vector<vector<int>> result;
        
        // Fix one of the element at the first position and call the same fnction for rest for the elements
        int i, j;
        for (i = 0; i < v.size(); i++)
        {
            // Copy orginal vector
            vector<int> temp(v.begin(), v.end());
            
            // Erase ith element 
            temp.erase(temp.begin() + i); // This will be 1 less than orignal vector
            
            auto res = __permute(temp);
            
            // upon return, append this removed element to each of the result
            
            for (j = 0; j < res.size(); j++)
            {
                vector<int> _r(res[j].begin(), res[j].end()); // copying
                // insert removed element to the beginning
                _r.insert(_r.begin(), v[i]);
                
                // Add this result to the final result
                result.push_back(_r);
            }
        }
        
        return result;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        return __permute(nums);
        
    }
};
