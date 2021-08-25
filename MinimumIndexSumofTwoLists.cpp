/*
599. Minimum Index Sum of Two Lists

Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

 

Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Example 3:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Burger King","Tapioca Express","Shogun"]
Output: ["KFC","Burger King","Tapioca Express","Shogun"]
Example 4:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KNN","KFC","Burger King","Tapioca Express","Shogun"]
Output: ["KFC","Burger King","Tapioca Express","Shogun"]
Example 5:

Input: list1 = ["KFC"], list2 = ["KFC"]
Output: ["KFC"]
 

Constraints:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the stings of list1 are unique.
All the stings of list2 are unique.

*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        map<string, int> m1;
        
        vector<pair<int, string>> res;
        
        // Convert list1 and list2 to set1 and set2
        
        auto iter  = list1.begin();
        
        int i = 0;
        while (iter != list1.end())
        {
            m1[*iter] =  i;
            iter++;
            i++;
        }
        
        // We can Find out common strings in this loop as well.
        
        i = 0;
        iter = list2.begin();
        while (iter != list2.end())
        {
            auto iter1 = m1.find(*iter); 
            if (iter1 != m1.end()) {
                int sum_idx = i + (*iter1).second;
                res.push_back(make_pair(sum_idx, *iter));
            }
            iter++;
            i++;
        }
        
        // Now sort res vector
        std::sort(res.begin(), res.end());
        
        // Assuming sorted in ascending order, get first index_sum items
        
        int prev = -1;
        
        auto iter2 = res.begin();
        
        vector<string> out_res;
        
        while (iter2 != res.end()) {
            
            
            if (prev == -1) {
                prev = (*iter2).first;
                out_res.push_back((*iter2).second);
            } else if (prev != (*iter2).first) break;
            else {
                out_res.push_back((*iter2).second);
            }
            
            iter2++;
        }
        
        return out_res;
        
    }
};

/*

Success
Details 
Runtime: 84 ms, faster than 62.76% of C++ online submissions for Minimum Index Sum of Two Lists.
Memory Usage: 38.6 MB, less than 30.76% of C++ online submissions for Minimum Index Sum of Two Lists.

*/
