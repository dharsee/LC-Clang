/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/


// C CODE



int getMSBSetBit(int* nums, int numsSize)
{
    int i;
    int msb = 0;
    int j = 0;
    
    for (i = 0; i < numsSize; i++)
    {
        j ^= nums[i];
    }
    
    int k = 0;
    while (j && k < 32)
    {
        j = j >> 1;
        //printf(" \n%d ", k);
        k++;
    }
    
    return k;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    
    int *res = (int*) calloc(2, sizeof(int));
    if (!res)
    {
        printf("\nFailed to calloc .... \n");
        return NULL;
    }
    
    if (returnSize) *returnSize = 2;
    
    int msb = getMSBSetBit(nums, numsSize);
    
    int  g1 = 0, g2 = 0;
    
    msb = (msb > 0) ? msb - 1: 0;
    //printf("\n MSB = %d ", msb);
    
    
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if ((nums[i] >> msb) & 0x1)
        {
            //printf("\n Gr 1  = %d ", nums[i]);
            g1 ^= nums[i];
        }
        else
        {
            //printf("\n Gr 2  = %d ", nums[i]);
            g2 ^= nums[i];
        }
    }
    
    res[0] = g1;
    res[1] = g2;
    
    return res;

}




// C++ Code


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        // To find the 2 unique number in an array where every other elemnts are duplicate
        // there few more solutions are available
        // 1. Sort and find; But Time complexity would be O(NlogN)
        // 2. Method 2, take the advantage of binary digit property to solve this problem
        // 
        // When entire array has duplicate elements except one, to find that element we would do XOR to eliminate duplicates
        
        // We can take advantage of this property to identify 2 unique in an duplicated array
        // 1. Perform XOR on all the elements
        // 2. Find the first bit set from right in the XORed result
        // 3. Group array elements as per this bit position, so that each number will go in one group (you will have 2 groups)
        // 4. Perform XOR on the group level to get unique elements in that group
        // 5. At the end, you will have 2 unique elements ready from their corresponding groups.
        
        
        // This method is way better than Sort and verify
        
        int n = nums.size();
        vector<int> res(2, 0);
        
        if (n <= 0) return res;
        
        int xor_res = 0;
        int i = 0;
        
        // Find XOR of all the elements in the array
        while (i < n)
        {
            xor_res ^= nums[i];
            i++;
        }
        
        // Now we have XOR of all elemets, now need to find first set bit from right in the result
        
        int temp = xor_res;
        int pos = 0;
        
        while(temp)
        {
            if (temp & 0x01)
            {
                break;
            }
            pos++;
            temp = temp >> 1;
        }
        
        //Now we know the position to group them
        
        
        i = 0;
        while (i < n)
        {
            if (nums[i] & (1 << pos))
            {
                res[0] ^= nums[i];
            }
            else
                res[1] ^= nums[i];
            i++;
        }
        
        return res;
    }
};
