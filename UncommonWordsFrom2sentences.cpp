/*
884. Uncommon Words from Two Sentences

We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.


*/


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        
        unordered_map<string, int>  hmap;
        int i, j, asz, bsz;
        
        asz = A.length();
        bsz = B.length();
        
        i = 0;
        j = 0;
        
        string as, bs;
        
        while (i < asz && j < bsz)
        {
            if (A[i] == ' ')
            {
                hmap[as]++;
                while (i < asz && A[i] == ' ') i++;
                
                as = "";
            }
            else
            {
                as += A[i];
                i++;
            }
            
            if (B[j] == ' ')
            {
                //cout << endl << "pushing this word '" << bs << "' to hmap ";
                hmap[bs]++;
                while (j < bsz && B[j] == ' ') j++;
             
                bs = "";
            }
            else
            {
                bs += B[j];
                j++;
            }
        }
        
        // Left - over cases
        
        
        while (i < asz)
        {
            if (A[i] == ' ')
            {
                hmap[as]++;
                while (i < asz && A[i] == ' ') i++;
                
                as = "";
            }
            else
            {
                as += A[i];
                i++;
            }
        }
        
        while (j < bsz)
        {
            if (B[j] == ' ')
            {
                hmap[bs]++;
                while (j < bsz && B[j] == ' ') j++;
             
                bs = "";
            }
            else
            {
                bs += B[j];
                j++;
            }
        }
    
        hmap[as]++;
        hmap[bs]++;
    
        vector<string> res;
        // Now scan hmap to build unique words

        unordered_map<string, int>::iterator iter = hmap.begin();

        while (iter != hmap.end())
        {
            //cout << endl << "At End word [" << (*iter).first  << "]";
            if ((*iter).second == 1 && (*iter).first != "")
                res.push_back((*iter).first);
            iter++;
        }

        return res;
    }
};
