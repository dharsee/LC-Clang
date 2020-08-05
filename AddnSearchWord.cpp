/*
Add and Search Word - Data structure design

Solution
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

Hint #1  
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

*/

class WordDictionary {
public:
    
    struct trie
    {
        char ch;
        int ends;
        struct trie *child[26]; //since input restricted to lowercase letters
    };
    typedef struct trie Trie;
    
    Trie * getNode(char ch)
    {
        Trie *node = new Trie;
        node->ch = ch;
        node->ends = 0;
        
        for (int i = 0; i < 26; i++)
            node->child[i] = NULL;
        
        return node;
    }
    
    Trie *root = NULL;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        
        root = getNode('/');
        
    }
    
    void dump(Trie *root)
    {
        if (!root) return;
        
        printf("%c", root->ch);
        
        for (int i = 0; i < 26; i++)
        {
            if (root->child[i])
                dump(root->child[i]);
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        int n = word.length();
        if (n == 0) return;
        
        int i, j, k;
        
        Trie *curr = root;
        
        i = 0;
        while(i < n)
        {
            char indx = word[i] - 'a';
            
            if (curr->child[indx] == NULL)
            {
                curr->child[indx] = getNode(word[i]);
            }
            curr = curr->child[indx];
            
            i++;    
        }
        
        if (curr)
        {
            curr->ends++;
        }
    }
    
    bool __search(string word, int index, Trie *root) {
        
        //printf(" Index (%d) ", index);
        
        int n = word.length();
        //if (n == index && root && root->ends) return true;
        if (n == index)
        {
            /* This optmization helped to pass TimeLimit Exceed error....compared to above check
            if (root && root->ends) return true;
            else return false;
        }
                
        if (!root) return false;
        
        
        if (word[index] == '.')
        {
            int i = 0;
            for (i = 0; i < 26; i++)
            {
                if (root->child[i])
                {
                    if(__search(word, index + 1, root->child[i])) return true;
                }        
            }
            //Exhasted so return false;
            return false;
        }
        else
        {
            int child_indx = word[index] - 'a'; 
            if (child_indx < 0 || child_indx > 25) return false;
            //printf(" Child (%c)(%d) ", word[index], child_indx);
            if (root->child[child_indx])
            {
                return __search(word, index + 1, root->child[child_indx]);
            }
            else
                return false;
        }
     }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        //dump(root);
        
        int n = word.length();
        if (n == 0) return false;
        
        return __search(word, 0, root);
        
        
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

