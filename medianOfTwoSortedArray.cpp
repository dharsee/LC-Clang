/*
4. Median of Two Sorted Arrays
Hard
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    inline
    double handleOneEmpty(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int target_indx = (len1 + len2) / 2;
        
        // IF one of them is empty then answer should be middle of other
        if (len1 == 0)
        {
            if ((len1 + len2) & 0x1) // ODD, get middle
                return nums2[target_indx];
            else
            {
                if (target_indx == 0) return (double)(nums2[0] + nums2[1])/2.0;
                
                return (nums2[target_indx-1] + nums2[target_indx])/2.0;
            }
        }
        
        if (len2 == 0)
        {
            if ((len1 + len2) & 0x1) // ODD, get middle
                return nums1[target_indx];
            else
            {
                if (target_indx == 0) return (double)(nums1[0] + nums1[1])/2.0;
                
                return (nums1[target_indx-1] + nums1[target_indx])/2.0;
            }
        }
    
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int target_indx = (len1 + len2) / 2;
        int curr = 0;
        double m1 = 0, m2 = 0;
        
        int found  = 0;
        
        
        if (len1 == 0 || len2 == 0)
            return handleOneEmpty(nums1, nums2);
        
     
        //printf("\n len1 = %d len2 = %d target = %d ", len1, len2, target_indx);
     
        // Try to scan both arrays and track last two elements and look for middle index to stop
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (nums1[i] <= nums2[j])
            {
                m1 = nums1[i];
                i++;
            }
            else
            {
                m1 = nums2[j];
                j++;
            }
            
            if (curr == target_indx) 
            {
                found  = 1;
                //break;
                goto DONE;
            }
            m2 = m1;
            
            curr++;
        }
        
        
        // Check for left over from first array
        while (i < len1)
        {
            m1 = nums1[i];
            
            if(curr == target_indx) 
            {
                found  = 1;
                goto DONE;
            }
            i++;
            curr++;
            
            m2 = m1;
        }
        
        // Check for left over from Second array
        while (j < len2)
        {
            m1 = nums2[j];
            
            if(curr == target_indx) 
            {
                found  = 1;
                goto DONE;
            }
            
            j++;
            curr++;
            
            m2 = m1;
        }
        
        
    DONE:
        //printf("\n len1 = %d len2 = %d target = %d ", len1, len2, target_indx);
        
        if (found) // In general, we alway have found 
        {
            if ((len1+len2) & 0x1) // ODD, only one number is enough
                return m1;
            else
            {
                return (m1+m2) / 2;
            }
        }
        
        return -1;
    }
};
