/*
Combination Sum

Solution
Given an array of distinct integers candidates and a target integer target, return a list of all unique 
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of 
at least one of the chosen numbers is different.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/


class Solution {
public:
    
    // Method 1; using set of vectors for res; which is not needed
    void generate1(vector<int>& candidates, int start, int target, 
                  vector<int> curr_res, set<vector<int>> &res)
    {
        /*
        printf("\n Target = %d , curr [", target);
        int k = curr_res.size();
        for (int j = 0; j < k; j++) printf(" %d, ", curr_res[j]);
        printf("]");
        */
        int i, n = candidates.size();
        if (target < 0 || n <= 0) // This combination is invalid so return
            return;
        
        if (target == 0) // we meet the target; add curr_res to res
        {
            //sort(curr_res.begin(), curr_res.end()); // This is not needed 
            res.insert(curr_res);
            
            return;
        }
        
        // start from given index and keep incrementing
        for (i = start; i < n; i++)
        {
            // Add current element to the result set and see if you get answer or not
            curr_res.push_back(candidates[i]);
            generate1(candidates,  i, target - candidates[i], curr_res, res);
                
            // Backtrack
            // remove this element and try
    
            curr_res.pop_back();        
        }
    }
    
    
    // Method 2; Using vector of vector as res
    void generate2(vector<int>& candidates, int start, int target, 
                   vector<int> curr_res, vector<vector<int>> &res)
    {
        /*
        printf("\n Target = %d , curr [", target);
        int k = curr_res.size();
        for (int j = 0; j < k; j++) printf(" %d, ", curr_res[j]);
        printf("]");
        */
        int i, n = candidates.size();
        if (target < 0 || n <= 0) // This combination is invalid so return
            return;
        
        if (target == 0) // we meet the target; add curr_res to res
        {
            res.push_back(curr_res);
            return;
        }
        
        // start from given index and keep incrementing
        for (i = start; i < n; i++)
        {
            // Add current element to the result set and see if you get answer or not
            curr_res.push_back(candidates[i]);
            generate2(candidates,  i, target - candidates[i], curr_res, res);
                
            // Backtrack
            // remove this element and try
    
            curr_res.pop_back();        
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        set<vector<int>> res_set;
        vector<vector<int>> res_vect;
        vector<vector<int>>  res;

        vector<int> curr_res;
        
        //Method 1; using set of vector for res, which is no need 
        generate1(candidates, 0, target, curr_res, res_set);    
        
        // Convert set to vector
        auto iter = res_set.begin();
        
        while (iter != res_set.end())
        {
            res.push_back(*iter);
            iter++;
        }
        
        return res;
        
    
        /*
        // Method 2; using vector of vector for res
        generate(candidates, 0, target, curr_res, res_vect);    
        
        return res_vect;
        
        */
        
    
        
    }
    
    /*
    
    168 / 168 test cases passed.
Status: Accepted
Runtime: 64 ms
Memory Usage: 19.1 MB
Submitted: 5 minutes ago

    
    */
};
