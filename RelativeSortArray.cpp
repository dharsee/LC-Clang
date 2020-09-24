/*
1122. Relative Sort Array
Easy

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 

Constraints:

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.

*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        //1. Build frequency table on arra1 --> unordred_map<int, int>
        //2. scan second array from 0th index and see how many times this appeared in arr1
        //3. Add these many times in the result array and remove it from hash map
        
        //4. At the end, copy all remaining elements from unordered map to vector and then sort them 
        //5. Append this sorted vector to the result in ascending order
        
        int i, j, k, n1 = arr1.size(), n2 = arr2.size();
        
        if (n1 == n2) return arr2;
        
        unordered_map<int, int> hmap;
        vector<int> res(n1, 0);
        
        //1. Build Hash map on arr1
        for (i = 0; i < n1; i++)
        {
            hmap[arr1[i]]++;
        }
        
        // 2. Scan arr2
        j = 0;
        for (i = 0; i < n2; i++)
        {
            /*
            // Alternate way to access hmap elements
            int count = hmap[arr2[i]]; // Since we know that arr2 is subset of arr1
            
            for (k = 0; k < count; k++)
            {
                res[j++] = arr2[i];
            }
            hmap[arr2[i]] = -1;
            */
            
            
            auto iter = hmap.find(arr2[i]);
            if (iter != hmap.end()) // found and should be 
            {
                for (k = 0; k < iter->second; k++)
                {
                    res[j++] = arr2[i];
                }
                
                // Remove it from the hmap; this may cost us more
                // Try to invalidate it with negative counter
                //hmap.remove(iter);
                hmap[arr2[i]] = -1; 
            }
            else 
            {
                cout << endl << "Somethig is not correct ...";
            }
            
        }
     
        
        // Now scan hmap to find left over elements 
        vector<int> left_over;
        auto iter = hmap.begin();
        
        while (iter != hmap.end())
        {
            int count = iter->second;
            
            if (count == -1)
            {
                iter++;
                continue;
            }
            
            for (k = 0; k < count; k++) left_over.push_back(iter->first);
            
            iter++;
        }
        
        // Sort left over array
        sort(left_over.begin(), left_over.end());
        
        /*
        // Manual way of copying vector to another vector
        auto iter2 = left_over.begin();
        while (iter2 != left_over.end())
        {
            res[j++] = *iter2;
            iter2++;
        }
        */
        
        copy(left_over.begin(), left_over.end(), res.begin() + n1 - left_over.size());

        return res;
        
    }
    
    
    /*
    Success
Details 
Runtime: 4 ms, faster than 92.49% of C++ online submissions for Relative Sort Array.
Memory Usage: 8.2 MB, less than 16.63% of C++ online submissions for Relative Sort Array.
    
    */
};
