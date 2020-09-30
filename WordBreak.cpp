/*
 Word Break

Solution
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented 
into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> dict;
        
        // BUILD set
        int i, n = wordDict.size();
        
        for (i = 0; i < n; i++)
            dict.insert(wordDict[i]);

        
        // Maintain DP array 
        
        n = s.length();
        vector<bool> dp(n + 1, false);
        
        dp[n] = true;
        
        string t;
        for(int j = n - 1; j >= 0; j--) 
        {
            t = "";
            for(int k = j; k < n; k++)
            {
                t = t + s[k];
                
                if(dict.find(t) == dict.end()) continue;
                
                if(dp[k+1])
                {
                    dp[j] = true;
					break;
				}
            }
        }
        
        return dp[0];
        
    }
};


#if 0

class Solution {
    
    
    /*
    This solution has problem with below input
    "aaaaaaa"
    ["aaaa","aaa"]
    */
    
    struct trie_s
    {
        char ch;
        int ends;
        struct trie_s *childs[26]; // Assuming dict will have lower-case english letters
    };
    
    typedef struct trie_s TRIE; 
    
public:
    
    TRIE * getNode(char ch)
    {
        TRIE *node = new TRIE;
        
        node->ch = ch;
        node->ends = 0;
        
        for (int i = 0; i < 26; i++)
            node->childs[i] = NULL;
        
        return node;
    }
    
    void insert(TRIE *root, string word)
    {
        TRIE *curr = NULL;
        
        //getNode(ch);
        
        if (root == NULL)
        {
            //root = curr;
            printf("\nExpecting root is non-NULL, but it is null ..");
            return;
        }
        
        
        int i, n = word.length();
        
        curr = root;
        for (i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            
            if (curr->childs[index] == NULL)
                curr->childs[index] = getNode(word[i]);
            
            curr = curr->childs[index];
            
        }
        
        // Now mark ends as non-zero
        
        curr->ends++;
    }
    
    bool search(TRIE *root, string s)
    {
        if (!root) return false;
        int i, n = s.length();
        
        if (n == 0) return true;
        
        TRIE *curr = root;
        bool last_ended = false;
        
        for (i = 0; i < n; i++)
        {
            cout << endl << " Looking for '" << s[i] << "'";
            last_ended = false;
            int index = s[i] - 'a';
            if (curr->childs[index])
            {
                cout << " Found and ends = " << curr->childs[index]->ends;
                if (curr->childs[index]->ends)
                {
                    last_ended = true; 
                    curr = root;
                }
                else
                {
                    curr = curr->childs[index];
                    
                }
            }
            else
            {
                //cout << " Not Found --- returning false ";
                return false;
            }
        }
        
        printf("\n i = %d n = %d last_ended  = %d ", i, n, last_ended);
        //if (i < n) return false;
        if (last_ended == false) return false;
        
        return true;
    }
    
    void dump(TRIE *root)
    {
        if (!root)
        {
            //printf("\n");
            return;
        }
        
        printf ("%c[%d] -> ", root->ch, root->ends);
        if (root->ends) printf("\n");
        
        for (int i = 0; i < 26; i++)
            if (root->childs[i]) dump(root->childs[i]);
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // Solve this by using TRIE datastrucure
        // Build TRIE using dict words
        // Search the input string s on TRIE to confirm
        
        TRIE *root = getNode('/');
        
        // BUILD TRIE
        int i, n = wordDict.size();
        
        for (i = 0; i < n; i++)
        {
            insert(root, wordDict[i]);
            
            printf("\n i = %d Dumpint TRIE : \n", i);
            dump(root);
            
        }
                            
        printf("\n\n\n Dumping TRIE : \n");
        dump(root);
        
        
        return search(root, s);
        
    }
};
#endif


/*

43 / 43 test cases passed.
Status: Accepted
Runtime: 40 ms
Memory Usage: 22.8 MB
Submitted: 1 minute ago



*/
