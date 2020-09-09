/*
Compare Version Numbers

Solution
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.


*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n1 = version1.length(), n2 = version2.length();
        
        if (n1 == 0 && n2 == 0) return 0;
        if (n1 && n2 == 0) return 1;
        if (n1 == 0 && n2) return -1;
        
        // scan each version string and chop sub-version and compare
        // any time if you detect unequal then return the answer based on 1/-1
        // if they are equal then keep checking until you reach end of the string
        
        // There may be cases where one of the string is smaller in len than other
        // In that case, exit from common loop and check for left over and see if they are non-zero or not
        // if rest of the string is zero then return as EQUAL
        // otherwise return based on their position 1/-1
        
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            string v1, v2;
            long int iv1, iv2;
            
            // chop sub-version from v1, v2
            int k = i;
            while (i < n1 && version1[i] != '.') i++;
            
            v1 = version1.substr(k, i - k);
            //iv1 = atol(v1); 
            iv1 = std::stol(v1, NULL);
            
            // chop sub-version from v1, v2
            k = j;
            while (j < n2 && version2[j] != '.') j++;
            
            v2 = version2.substr(k, j - k);
            //iv2 = atol(v2); 
            iv2 = stol(v2, NULL);
            
            //cout << endl << "v1 [" << v1 << ", " << iv1 << "] v2 [" << v2 << ", " << iv2 << "]";
            
            // Compare and decide whether to continue or return
            
            if (iv1 > iv2) return 1;
            if (iv1 < iv2) return -1;
            
            // If they are equal then look for next sub-version
            
            
            i++;
            j++;
        }
        
        // Process left-over
        
        while (i < n1)
        {
            string v1;
            long int iv1;
            // We may return 1 if we find non-zero sub-version
            // chop sub-version from v1, v2
            int k = i;
            while (i < n1 && version1[i] != '.') i++;
            
            v1 = version1.substr(k, i - k);
            //iv1 = atol(v1); 
            iv1 = stol(v1, NULL);
            if (iv1) return 1;
            
            i++;
        }
        
        while (j < n2)
        {
            string v2;
            long int iv2;
            // We may return -1 if we find non-zero sub-version
            int k = j;
            while (j < n2 && version2[j] != '.') j++;
            
            v2 = version2.substr(k, j - k);
            //iv2 = atol(v2); 
            iv2 = stol(v2, NULL);
            
            if (iv2) return -1;
            
            j++;
        }
        
        
        return 0; // Since we have passed all the check and they appear as same.
        
        
    }
};


/*
Submission Detail
72 / 72 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 6.2 MB
Submitted: 0 minutes ago


*/
