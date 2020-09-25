/*
179. Largest Number
Medium

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.


*/

class Solution {
    
    // This is the way to define custom comparator function for sort
    // IT should be <static>
    bool static compare2(string a, string b)
    {
        string s1 = a + b;
        string s2 = b + a;
        
        //return s1.compare(s2); // This way of comparing is not helping
        return s1 > s2; // This is helping to sort accoring to lexicographical order
    }
    
public:
    
    void dump(vector<string> &v)
    {
        int i, n = v.size();
        
        cout << endl;
        for (i = 0; i < n; i++)
            cout << v[i] << ",  ";
    }
    
    
    
    string largestNumber(vector<int>& nums) {
       
        vector<string> temp;
        int i;
        string res;
        
        int n = nums.size();
        
        for (i = 0; i < n; i++)
            temp.push_back(to_string(nums[i]));

        //sort(temp.begin(), temp.end(), greater<>());
        
        sort(temp.begin(), temp.end(), compare2);
        
        /*
        // This is alternate way to define custom comparator
        sort(temp.begin(), temp.end(), [](string &a, string &b){
            string order1 = a + b;
            string order2 = b + a;
            
            //return order2.compare(order1); // This is not helping in this case
            return order1 > order2; // This is helping 
        });
        */
        
        //dump(temp);
        
        bool all_are_zeros = true; // This is needed to know that all result values are zeros or not
        // When all the values are zero, just return "0";
        for (i = 0; i < n; i++)
        {
            if (temp[i] != "0") all_are_zeros = false;
            res += temp[i];
        }
        
        if (all_are_zeros) return "0";
        
        
        return res;
  
  
  }
  
  /*
  
  222 / 222 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 11.7 MB
Submitted: 6 minutes ago

  
  */
};






// Another attempt to solve this problem

#if 0

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        // Convert integer vector to string vector then sort with custom comparator then build the result
        int i, n = nums.size();
        
        if (n == 0) return "";
        if (n == 1) return to_string(nums[0]);
        
        vector<string> temp(n);
        string res;
        
        // Convert integer vector to string vector
        
        bool all_are_zeros = true;
        for (i = 0; i < n; i++)
        {
            if (nums[i]) all_are_zeros = false;
            temp[i] = to_string(nums[i]);  
        } 
        
        if (all_are_zeros) return "0";
        
        //Sort string vector with custom comparator
        sort(temp.begin(), temp.end(), [](string &a, string &b){
            string order1 = a + b;
            string order2 = b + a; // Only these 2 possible combinations exist
            
            return order1 > order2;
        });
        
        
        // Build result string by scanning sorted string vector
        for (i = 0; i < n; i++)
        {
            res += temp[i];
        }
        
        return res;
        
        
    }
};

/*

222 / 222 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 11.4 MB
Submitted: 0 minutes ago

*/
#endif
