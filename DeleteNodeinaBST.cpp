/*
450. Delete Node in a BST
Medium -  4059 - 129 - dd to List - Share

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool is_leaf_node_target(TreeNode* root, int key){
        if (root == NULL) return false;
        
        // Leaf node on left subtree
        if (root->left && root->left->val == key && root->left->left == NULL && root->left->right == NULL) {
            root->left = NULL;
            return true;
        }
        // Leaf node on right subtree
        if (root->right && root->right->val == key && root->right->left == NULL && root->right->right == NULL) {
            root->right = NULL;
            return true;
        }
        
        // Do the same for left and right sub-trees
        bool l = is_leaf_node_target(root->left, key);
        if (l == true) return true;
        bool r = is_leaf_node_target(root->right, key);
        if (r == true) return true;
        
        return false;
    }
    
    int findMin(TreeNode* root, TreeNode *parent) {
        if (root && root->left) {
            int val = root->left->val;
            if (root->left->left == NULL) {
                if (root->left->right) {
                    root->left = root->left->right;
                } else {
                    root->left = NULL;
                }
                return val;
            }
        return findMin(root->left, parent);
        } else {
            parent->right = root->right;
            return root->val;
        }
    }
    
    int findMax(TreeNode* root, TreeNode *parent) {
        if (root && root->right) {
            int val = root->right->val;
            if (root->right->right == NULL) {
                if (root->right->left) {
                    root->right = root->right->left;
                } else {
                    root->right = NULL;
                }
                return val;
            }
        return findMax(root->right, parent);
        } else {
            parent->left = root->left;
            return root->val;
        }
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (!root) return NULL;
        //if (root->left == NULL && root->right == NULL) return root;    
        
        // is target is root?
        if (root->val == key) {
            int _min = 0;
            int _max = 0;
            if (root->right) {
                _min = findMin(root->right, root);
                root->val = _min;
                return root;
            } else if (root->left) {
                _max = findMax(root->left, root);
                root->val = _max;
                return root;
            } else { // Single node case
                return NULL;
            }
        }
        
        /*
        
        // remove link if target node is leaf node.
        if (is_leaf_node_target(root, key)) return root;
        */
        
        // Otherwise case
        cout << endl << "Else case ....";
        
        TreeNode *curr = root;
        while (curr) {
            if (curr->left && curr->left->val == key) {
                if (curr->left->left == NULL && curr->left->right == NULL) curr->left = NULL;
                else if (curr->left->left == NULL && curr->left->right) curr->left = curr->left->right;
                else if (curr->left->left && curr->left->right == NULL) curr->left = curr->left->left;
                else { // Both the children present for the key node
                    int _max = findMax(curr->left->left, curr->left); // He will take care of removing the node
                    curr->left->val = _max;
                } 
                return root;
            } else if (curr->right && curr->right->val == key) {
                if (curr->right->left == NULL && curr->right->right == NULL) curr->right = NULL;
                else if (curr->right->left == NULL && curr->right->right) curr->right = curr->right->right;
                else if (curr->right->left && curr->right->right == NULL) curr->right = curr->right->left;
                else { // Both the children present for the key node
                    int _min = findMin(curr->right->right, curr->right); // He will take care of removing the node
                    curr->right->val = _min;
                }        
                return root;    
            }
            
            // Move curr based on the target and curr val
            if (curr->val > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        
        cout << endl << "Uncovered Case ...... ";
        return root;
        
    }
};

/*
Success
Details 
Runtime: 24 ms, faster than 97.26% of C++ online submissions for Delete Node in a BST.
Memory Usage: 32.6 MB, less than 75.07% of C++ online submissions for Delete Node in a BST.
 */

