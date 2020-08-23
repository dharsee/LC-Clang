/*
Stream of Characters

Solution
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
   Hide Hint #1  
Put the words into a trie, and manage a set of pointers within that trie.


*/



/*
Implement TRIE data structure to hold dictionary
maintain queried field to track whether its parents queried or not in the path
if any of them already queried and this char is exists then return TRUE
otherwise return FALSE
*/

class StreamChecker {
    
    struct trie_s
    {
        char ch;
        int ends;
        struct trie_s *child[26]; //for his possible children
    };
    
    typedef struct trie_s TRIE;
    
    TRIE *root;
    
    deque<char> stream; // This is used to track previous queries' characters
    
public:
    // utility function to build trie TREE
    
    inline TRIE* getNode(char ch)
    {
        TRIE *node = new TRIE();
        node->ch = ch;
        node->ends = 0;
        
        //children
        for (int i = 0; i < 26; i++)
            node->child[i] = nullptr;
        
        return node;
    }
    
    // Assuming root exists and initialized with '/'
    // Build trie with reverse of the given word so that searching will be easier for this problem
    void __build_trie(TRIE *root, string &word)
    {
        int i = 0, n = word.length(), k, l;
        
        TRIE *curr = root;
        i = n - 1;
        while (i >= 0)
        {
            int indx = word[i] - 'a';
 
            if (curr->child[indx] == nullptr)
                curr->child[indx] = getNode(word[i]);
            
            curr = curr->child[indx];
            i--;
        }
        
        if (curr) curr->ends++;
        
    }
    
    
    StreamChecker(vector<string>& words) {
        // Initialize TRIE data structure's root node
        
        root  = getNode('/');
        if (root == nullptr)
        {
            printf("\n Failed to create root node ...\n");
        }
        
        int i = 0, n = words.size();
        
        for (i = 0; i < n; i++)
        {
            __build_trie(root, words[i]);
        }
    }
    
    
    bool check()
    {
        // input should be streams, act as word and dict is root
    
        int i, j, n = stream.size();
        TRIE *curr = root;
        i = 0;
        while (i < n)
        {
            int indx = stream[i] - 'a';
            if (curr->child[indx] == nullptr) return false;
            else
            {
                curr = curr->child[indx];
                if (curr->ends) return true;
            }
            
            i++;
        }

        return false; //exhausted 
    }
    
    
    bool query(char letter) {
        
        // Push fron to the deque
        stream.push_front(letter);
        
        //now check this word is exist in the dictionary or not.
            
        //return check(stream);
        return check(); // stream is available in this class itself
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
