/*
Serialize and Deserialize BST

Solution
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a 
file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization 
algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Codec {
public:
    
    /*
        Learning point is that - To construct BST, we only need pre-order traversal
        Once we have pre-order traversal, we can BUILD BST by scanning each root node recursively
        make first element as root, find left sub list and right sub list
        do the same by passing left sub list to build left node
        do the same by passing right sub list to build right node
    */
    
    void preorder(TreeNode *root, string &res)
    {
        if (!root) return;
        
        res += to_string(root->val);
        res += " "; // Delimiter
        
        // Do it for left subTree and Right subTree
        preorder(root->left, res);
        preorder(root->right, res);
    }
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        
        string res;
        preorder(root, res);
        return res;
    }

    void getInt(string &data, vector<int> &out)
    {
        string t;
        
        int n = data.length();
        int i;
        
        for (i = 0; i < n; i++)
        {
            if (data[i] == ' ') // delimiter
            {
                if (t.length() > 0)
                {
                    out.push_back(stoi(t));
                    t = "";
                }
            }
            else
                t += data[i];
        }
        
        if (t.length() > 0) out.push_back(stoi(t));
    }
    
    void dumpv(vector<int> &input, string msg)
    {
        int n = input.size();
        int i = 0;
        
        cout << endl << msg;
        
        for (i = 0; i < n; i ++)
            printf(" %d ", input[i]);    
    }
    
    TreeNode * buildBST(vector<int> &pre, int start, int end)
    {
        if (start > end) return NULL;
        
        TreeNode *root = new TreeNode(pre[start]);
        
        // find the partition where left and right subtrees are separated
        int i = 0;
        for (i = start; i <= end; i++)
        {
            if (pre[i] > pre[start]) break;
        }
        
        // BUILD LEFT sub tree using left part of the list and right sub tree using right part of the list
        root->left = buildBST(pre, start + 1, i - 1);
        root->right = buildBST(pre, i, end);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        
        vector<int> pre;
        int n = data.length();
        if (n == 0) return NULL;
        
        // Convert preodert string to integer vector
        getInt(data, pre);
        
        //dumpv(pre, "PRE-order vector : ");
     
        return buildBST(pre, 0, pre.size() - 1);
    }
  
  /*
      62 / 62 test cases passed.
      Status: Accepted
      Runtime: 36 ms
      Memory Usage: 27.8 MB
      Submitted: 0 minutes ago
  */
      
      
};




// ANOTHER SOULTION which was taking longer time to complete but was a working solution


    
#if 0


/* This solution is failing to pass time limit since we are traversing two times and using those two 
traversal data to build the tree
*/

class Codec {
public:
    
    void preorder(TreeNode *root, string &res)
    {
        if (!root) return;
        
        // "D" - indicated delimiter
        res += "D" + to_string(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    
    void inorder(TreeNode *root, string &res)
    {
        if (!root) return;
        
        // "D" - indicated delimiter
        
        inorder(root->left, res);
        res += "D" + to_string(root->val);
        inorder(root->right, res);
    }
    
    void postorder(TreeNode *root, string &res)
    {
        if (!root) return;
        
        // "D" - indicated delimiter
        
        postorder(root->left, res);
        postorder(root->right, res);
        res += "D" + to_string(root->val);
    }
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res;
        
        string pre("PRE"), in("IN"), post("POST");
        
        preorder(root, pre);
        //cout << endl << "PRE " << pre;
        
        inorder(root, in);
        //cout << endl << "IN  " << in;
        //inorder(root, in);
        
        //postorder(root, post);
        
        res += pre;
        res += in;
        /*
        res += post;
        */
        // End by "D"
        res += "D";
        //cout << endl << res;
 
        
        return res;
        
    }
    
    void decode(string &data, vector<int> &pre, vector<int> &in, vector<int> &post)
    {
        int n = data.length();
        
        if (n <= 6) return; // 12 are added as part of delimiter
        
        // scan from 5 index
        int i = 4;
        int k = 0;
        string temp = "";
        
        
        while (i < n)
        {
            if (data[i] == 'I')
            {
                if (temp.length() > 0)
                {
                    //cout << "  going to push " << temp;
                    pre.push_back(stoi(temp));
                }
                break; // Indicates start of IN-ORDER data
            }
            
            if (data[i] == 'D')
            {
                if (temp.length() > 0)
                {
                    //cout << "  going to push " << temp;
                    pre.push_back(stoi(temp));
                }
                temp = "";
            }
            else
                temp += data[i];
            
            i++;
        }
        
        //cout << endl << "Pre-order was decoded sucessfully .. ";
        
        i += 3; // to skip "IND"
        temp = "";
        k = 0;
        while (i < n)
        {
            if (data[i] == 'P')
            {
                if (temp.length() > 0)
                {
                    //cout << "  IN going to push<P> " << temp;
                    in.push_back(stoi(temp));
                }
                break; // Indicates start of POST-ORDER data
            }
            
            if (data[i] == 'D')
            {
                //cout << "  IN going to push<D> " << temp;
                if (temp.length() > 0)
                {
                    
                    in.push_back(stoi(temp));
                }
                temp = "";
            }
            else
                temp += data[i];
            
            i++;
        }
        
        /*
        i += 5; // to skip "POSTD"
        temp = "";
        k = 0;
        while (i < n)
        {
            if (data[i] == 'D')
            {
                if (temp.length() > 0)
                {
                    post.push_back(stoi(temp));
                    temp = "";
                }
            }
            else
                temp += data[i];
            
            i++;
        }
        */
    }

    void dumpv(vector<int> &input, string msg)
    {
        int n = input.size();
        int i = 0;
        
        cout << endl << msg;
        
        for (i = 0; i < n; i ++)
            printf(" %d ", input[i]);
        
    }
    
    // *******************************************************************************//
    // COPIED FROM OLD SOLUTION 
    
        
    /*
    Algorithm would be 
        PRE ORDER {root, Left, Right}
        In-Order {Left, Root, Right}
    Pre-order will try to give you the root
    In-order will find its left children list and right children list
    Do this recursively
     */  
    
    
    int findpos(vector<int>& vect, int l, int h, int val)
    {
        while(l < h)
        {
            if (vect[l] == val) return l;
            l++;
        }
        return l;
    }
    
    int findpos2(vector<int>& pre, int pre_start, vector<int>& vect, int l, int h)
    {
        int i, j;
        
        int k = pre.size();
        for (i = pre_start; i < k; i++)
        {
            j = l;    
            while(j < h)
            {
                if (vect[j] == pre[i]) return j;
                j++;
            }
        }
        
        // Should not come here;
        return l;
    }
    
    TreeNode * getNode(int val)
    {
        TreeNode *root = new TreeNode;
        root->val = val;
        root->left = root->right = NULL;
        
        return root;
    }
    
    // Last param will help optimizing the TC
    void __buildTree(TreeNode *root, vector<int>& inorder, vector<int>& preorder,
                    int lstart, int lend, int rstart, int rend, int pre_order_start)
    {

        
        if (lstart < lend)
        {
            //devide left child and create link
            int pos = findpos2(preorder, pre_order_start, inorder, lstart, lend);
            TreeNode *curr = getNode(inorder[pos]);
            root->left = curr;
            
            // Do it for recursive
            __buildTree(root->left, inorder, preorder,
                    lstart, pos, pos + 1, lend, pre_order_start + 1);
            
        }
        

        if (rstart < rend)
        {
            //devide Right child and create link
            int pos = findpos2(preorder, pre_order_start, inorder, rstart, rend);
            TreeNode *curr = getNode(inorder[pos]);
            root->right = curr;
            
            // Do it for recursive
            __buildTree(root->right, inorder, preorder,
                    rstart, pos, pos + 1, rend, pre_order_start + 1);
            
            
        }
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n1 = inorder.size();
        int n2 = preorder.size();
        
        if (n1 == 0 || n2 == 0) return NULL;
        
        // create root node
        TreeNode *root = getNode(preorder[0]);
        
        // Find the position in In-Order 
        int pos = findpos(inorder, 0, n1, preorder[0]);
        
        // Last param will help optimizing the TC
        __buildTree(root, inorder, preorder, 0, pos, pos+1, n1, 1);
        
        return root;
    }
    
// *******************************************************************************//
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        
        vector<int> pre, in, post;
        
        //cout << endl << "Decoding ...";
        //split string into traversal order data by reading delimiter added in the seriralize
        decode(data, pre, in, post);
    
        /*
        cout << endl << "DECODED TREE ORDER TRAVERSAL :";
        dumpv(pre,  "PRE  : ");
        dumpv(in,   "IN   : ");
        dumpv(post, "POST : ");
        */
        
        root = buildTree(pre, in);
        
        return root;
    }

    /*
    This solution works fine but exceeding time limit
        61 / 62 test cases passed.
    Status: Time Limit Exceeded
    Submitted: 0 minutes ago
    */
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

#endif

