/*
 Buddy Strings

Solution
Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. 
For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Constraints:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.

*/


class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        int al = A.length();
        int bl = B.length();
        
        if (al != bl) return false;
        
        int i;
        int freq[26] = {0};
        
        char d1 =' ', d2 = ' ';
        int p1 = -1, p2 = -1;
        
        int diff_count = 0;
        
        for (i = 0; i < al; i++)
        {
            freq[A[i]-'a']++;
            
            if (A[i] != B[i])
            {
                diff_count++;
                
                if (p1 == -1) p1 = i;
                else if (p2 == -1) p2 = i;
                else return false;
                
                if (diff_count > 2) return false; // May not get this chance
                    
            }
        }
        
        if (p1 == -1 && p2 == -1) // Means both the string are same
        {
            /*
            if any char is repeating then return true
            if all chars are unique then return false
            */
            
            int k = 0;
            for (k = 0; k < 26; k++)
            {
                if (freq[k] > 1) return true;
            }
            
            return false;
        }
        else if (p1 == -1 && p2 >= 0)
            return false;
        else if (p1 >= 0 && p2 == -1)
            return false;
        else
        {
            char temp = A[p1];
            A[p1] = A[p2];
            A[p2] = temp;
            
            if (A == B) return true;
            else return false;
        }
        
    }
    
    /*

            29 / 29 test cases passed.
        Status: Accepted
        Runtime: 4 ms
        Memory Usage: 7.3 MB
        Submitted: 0 minutes ago
    
    */
};
