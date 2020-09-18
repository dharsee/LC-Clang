/*
506. Relative Ranks

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        
        vector<pair<int, int>> p;
        int n = nums.size();
        
        if (n == 0) return {""};
        
        int i, j, k;
        
        for (i = 0; i < n; i++)
            p.push_back({nums[i], i});
    
    
        // Sort based on the numbers
        
        sort(p.begin(), p.end(), greater<>());
        
        vector<string> res(n, "");
        
        // Fill first 3 spots based on the length
        if (n >= 1) res[p[0].second] += "Gold Medal";
        if (n >= 2) res[p[1].second] += "Silver Medal";
        if (n >= 3) res[p[2].second] += "Bronze Medal";
        
        i = 3;
        while (i < n)
        {
            res[p[i].second] += to_string(i+1);
            i++;
        }
        
        return res;
    }
};
