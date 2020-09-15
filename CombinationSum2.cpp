/*
40. Combination Sum II
Medium

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]


*/

class Solution {
public:
    /*
    void explore(vector<int> input, int index, int target, 
                 vector<int> curr_comb, int sum, vector<vector<int>> &res)
    */
    void explore(vector<int> input, int index, int target, 
                 vector<int> curr_comb, int sum, set<vector<int>> &res)
    {
        if (sum == target)
        {
            //res.push_back(curr_comb);
            res.insert(curr_comb);
            return;
        }
        

        
        //if (index > input.size()) return;
        
        // Just to check overflow conditions
        if(index >= input.size() || sum > target) return; 
        
        
        int i, n = input.size();
        
        while(index < n)
        {
            curr_comb.push_back(input[index]);
            sum += input[index];
            explore(input, index + 1, target, curr_comb, sum, res);

            // Get rid of last added element to see othe combinations
            curr_comb.pop_back();
            sum -= input[index];
            
            index++;
        }
        
    }
    
    void dump_set(set<vector<int>> set_res)
    {
        auto iter = set_res.begin();
        
        while (iter != set_res.end())
        {
            vector<int> t(*iter);
            
            int i = 0, n = t.size();
            
            printf("[");
            while (i < n)
            {
                printf(" %2d ", t[i]);
                i++;
            }
            printf("]\n");
            
            iter++;
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        set<vector<int>> set_res;
        
        vector<int> curr_comb;
        
        sort(candidates.begin(), candidates.end());
        //explore(candidates, 0, target, curr_comb, 0, res);
        explore(candidates, 0, target, curr_comb, 0, set_res);
        
        
        //set_res.insert(res.begin(), res.end());
        
        //dump_set(set_res);
        
        //restore to the array
        
        vector<vector<int>> ret(set_res.begin(), set_res.end());
        
        /*
        auto iter = set_res.begin();
        vector<vector<int>> ret;
        
        while (iter != set_res.end())
        {
            vector<int> t(*iter);
            ret.push_back(t);
            iter++;
        }
        
        */
        
        return ret;
        
        
        
    }
};
