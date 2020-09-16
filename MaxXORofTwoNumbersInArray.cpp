/*

Maximum XOR of Two Numbers in an Array

Solution
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

*/


class Solution {
    
    struct trie_s
    {
        //int val;
        struct trie_s *child[2];
    };
    
    typedef struct trie_s Trie;
    
    inline Trie * getNode()
    {
        Trie *root = new Trie;
        //root->val = val;
        root->child[0] = root->child[1] = NULL;
        
        return root;
    }
    
    void insert(int val, Trie *head)
    {
        Trie *curr = head;
        
        int i = 0;
        
        for (i = 31; i >= 0; i--)
        {
            int bit = (val >> i) & 1;
            if (!curr->child[bit])
                //curr->child[bit] = getNode(bit);
                curr->child[bit] = getNode();
            
            curr = curr->child[bit];
        }
        
        
    }
    
    int find22(int val, Trie *head)
    {
        int ans = 0;
        int i = 0;
        
        Trie *curr = head;
        
        for (i = 31; i >= 0; i--)
        {
            int bit = (val >> i) & 1;
            
            /*if (curr == NULL)
            {
                printf("\nFind :-  Curr is NULL  i = %d", i);
            }*/
            if (curr->child[!bit])
            {
                ans |= (1 << i);
                curr = curr->child[!bit];
            }
            else
                curr = curr->child[bit];
        }
        
        return ans;
    }
    
    
public:
    
    int findMaximumXOR(vector<int>& nums) {
        
        int i, j, m = 0, res = 0;
        
        int n = nums.size();
        if (n <= 1) return 0;
        //if (n == 1) return nums[0];
        if (n == 2) return nums[0] ^ nums[1];
     
        // Solve it by using TRIE data structure, values will be bit value of the each element in the array
        
        Trie *root = getNode();
        for (i = 0; i < n; i++)
        {
            insert(nums[i], root);
        }
        
        
        for (i = 0; i < n; i++)
        {
            res = max(res, find22(nums[i], root));
        }
        
        
        
        
        return res;
    }
    
    
    int findMaximumXOR2(vector<int>& nums) {
        
        int i, j, m = 0;
        
        int n = nums.size();
        if (n <= 1) return 0;
        //if (n == 1) return nums[0];
        if (n == 2) return nums[0] ^ nums[1];
        
        /*
        // Naive approach which will take O(N^2) runtime
        // And this is passing all test cases but it is taking longer runtime and causing "exceeding timelimit"
        // Need to find better appraoch which can reduce runtime by taking advantage of number theory
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                int t = 0;
                
                if ((t = nums[i] ^ nums[j]) > m) m = t;
            }
        }
        */
        
        
        
        
        return m;
    }
};
