/*
1209. Remove All Adjacent Duplicates in String II
Medium

Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing 
them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 
Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.

*/

class Solution {
public:
    
    string remove(string s, int k)
    {
        int n = s.length();
        if (n <= 1) return s;
        
        int count = 1, i = 1;
        
        while (i < n)
        {
            if (s[i-1] == s[i])
            {
                count++;
                
                if (count == k) break; // means we have something to work and remove duplicates
            }
            else
                count = 1;
            i++;
        }
        
        if (count == k)
        {
            //s.remove();
            string p1 = s.substr(0, (i-k) == 0 ? 1 : i - k+1);
            string p2 = s.substr(i+1);
            
            //string p3 = s.substr((i-k) == 0 ? 1 : i - k + 1, k);
            //cout << endl << "input [" << s << "], [" << p1 << ", " << p2 <<  "] removing [" << p3 << "]";
            
            // Now call againg with new string
            
            return remove(p1+p2, k);
        }
        
        return s;
    }
    
    string removeDuplicates(string s, int k) {
        
        int n = s.length();
        if (n == 0) return "";
        if (n == 1) return s;
        
        if (k <= 1) return s;
        
        //Sort will not work here; doing that we will loose original adjacency
        
        // Let's break this loop when we detect there is nothing to be done further
        string res = remove(s, k);
        
        return res;
    }
    
    
    /*
        Details 
        Runtime: 8 ms, faster than 99.16% of C++ online submissions for Remove All Adjacent Duplicates in String II.
        Memory Usage: 11.3 MB, less than 7.69% of C++ online submissions for Remove All Adjacent Duplicates in String II.
    
    */
};

