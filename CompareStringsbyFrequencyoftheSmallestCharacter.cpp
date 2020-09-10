/*
1170. Compare Strings by Frequency of the Smallest Character

Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.

Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
 

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.

*/

class Solution {
public:
    
    vector<int> fillFreq(vector<string> &q)
    {
        int nq = q.size();
        
        int hmap[26] = {0}; //Since input will be English lowercase letters
        
        vector<int> fq(nq, 0);
        int i, j;
        
        for (i = 0; i < nq; i++)
        {
            // Initialize hmap to zero
            
            for (j = 0; j < 26; j++)
                hmap[j] = 0;
            
            // compute frequency
            for (j = 0; j < q[i].size(); j++)
            {
                int indx = q[i][j] - 'a';
                //printf("\n [%c] Before hmap[%d] = %d", q[i][j], indx, hmap[indx]);
                hmap[indx]++;
            }
            
            //Find the fequency of the smallest character
            int f = 0;
            for (j = 0; j < 26; j++)
            {
                if (hmap[j])
                {
                    f = hmap[j];
                    break;
                }
            }
            
            fq[i] = f;
        }
        
        return fq;
    }
    
    
    void dumpFreq(vector<int> f)
    {
        int i = 0, n = f.size();
        
        printf("\n[");
        while( i < n)
            printf(" %d ", f[i++]);
        
        printf("]\n");
    }
    
    
    // Need to fix this binary search for this scenario
    int bin_search(vector<int> vect, int target)
    {
        int l = 0, h = vect.size() - 1, m = 0;
        
        
        if (h == 0)
        {
            if (target < vect[0]) return 1;
            else return 0;
        }
        
        //printf("\n Bin Search: Looking for %d, h = %d ", target, h);
        while (l < h)
        {
            m = ((h-l)/2) + l;
            
            //if (m < 0) break;
            
            //if (vect[m] == target) return vect.size() - m - 1;
            
            if (vect[m] > target)
                h = m - 1;
            else
                l = m + 1;
            
            
        }
        printf("\n Bin Search  L = %d h = %d m = %d  target = %d", l, h, m, target);
        //if (l==h) return 0;
        return vect.size() - l-1;
    }
    
    
    int count(vector<int> vect, int target)
    {
        int i, n = vect.size();
        
        for (i = 0; i < n; i++)
        {
            if (vect[i] > target) return n-i;   
        }
        
        return n-i;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        int nq = queries.size();
        int nw = words.size();
        
        
        vector<int> fq(nq, 0);
        vector<int> fw(nw, 0);
        
        // Calculate frequencies
        
        fq = fillFreq(queries);
        fw = fillFreq(words);
        
        vector<int> res;
        
        // Compute result vector
        
        //sort word frequency vector to do binary search
        sort(fw.begin(), fw.end());
        
        
        /*
        // Dump frequencies
        dumpFreq(fq);
        printf("\n Sorted .. ");
        dumpFreq(fw);
        */
        
        // Now scan each query freq and fill result vector based on word freq
        int i;
        for (i = 0; i < nq; i++)
        {
            //res.push_back(bin_search(fw, fq[i]));
            res.push_back(count(fw, fq[i])); // Linear search
        }
        
        return res;
        
    }
};
