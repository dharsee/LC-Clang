/*
212. Word Search II
Hard

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 
Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/


class Solution {
public:
    
    // Lets solve this problem by using Recursion(DFS) + TRIE data structure
    // Build TRIE data structure on words
    // scan DFS on borad to see if one of the TRIE is matching or not.
    // If they match add it to the result and move on
    // At the end, return result 
    
    
    struct Node
    {
        char ch;
        int ends;
        string word;
        struct Node *child[26]; // since there will only 26 characters (English lower case letters)
    };
    
    typedef struct Node Node;
    
    // Create a node and initialize it with default values then return it to the caller
    Node * getNode(char ch)
    {
        Node *node = new Node;
        
        node->ch = ch;
        node->ends = 0;
        node->word = "";
        
        int i = 0;
        while (i < 26)
        {
            node->child[i] = NULL;
            i++;
        }
        
        return node;
    }
     
    void insertToTrie(Node *root, string word)
    {
        if (root == NULL) return;
        
        Node *curr = root;
        
        int n = word.size();
        int i = 0;
        
        //if (n == 0) return;
        
        int indx = 0;
        while (i < n)
        //while(s[i])
        {
            char ch = word[i];
            indx = ch - 'a';
            if (curr->child[indx] == NULL)
            {
                Node *t = getNode(ch);
                curr->child[indx] = t;
                
            }
            curr = curr->child[indx];
            i++;
        }
        
        curr->word = word;
        curr->ends++;
    }
    
    
    void check(vector<vector<char>>& board, int i, int j, int r, int c, vector<string> &res, Node *curr)
    {
        int indx = board[i][j] - 'a';
        //printf("\n Index = %d, i= %d j = %d board[][] = ''%c'", indx, i, j, board[i][j]);
        
        // Base case for the recursion
        if (board[i][j] == '$' || curr->child[indx] == NULL )
            return;
        
        curr = curr->child[indx];
        if (curr->ends > 0)
        {
            res.push_back(curr->word);
            curr->ends--;
        }
        
        char ch = board[i][j];
        board[i][j] = '$'; // to avoid cycles
        
        if (i > 0)   // up
            check(board, i-1, j, r, c, res, curr);
        
        if (i < r-1) // DOWN
            check(board, i+1, j, r, c, res, curr);
            
        if (j > 0)   // Left
            check(board, i, j-1, r, c, res, curr);
        
        if (j < c-1) //Right
            check(board, i, j+1, r, c, res, curr);
        
        
        board[i][j] = ch; // restore it back
        
        
    }
    
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        int r, c;
        
        r = board.size();
        c = board[0].size();
        
        // BUILD TRIE DATA structure by scanning words
        int n = words.size();
        
        int i;
        
        Node *root = getNode('/');
        
        for (i = 0; i < n; i++)
        {
            insertToTrie(root, words[i]);
        }
        
        // Now scan board and try to see if char matches
        int j = 0;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                check(board, i, j, r, c, res, root);
            }
        }
        
        return res;
        
    }
};
