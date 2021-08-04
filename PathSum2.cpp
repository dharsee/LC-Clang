/*
Path Sum II

Solution
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

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
    void printVec(vector<int> &vec){
        int i, sz = vec.size();
        auto iter = vec.begin();
        
        while (iter != vec.end())
        {
            cout << " " << *iter << ",";
            iter++;
        }
    }
    
    // In-order traverse
    
    void traverse(TreeNode *root, int targetSum, int currSum, 
                  vector<int> &validPath,
                  vector<vector<int>> &res){
        
        if (!root) return;
        
        // First add this node into the path
        validPath.push_back(root->val);
        
        // Check its sum only if this is the leaf node
        if (root->left == NULL && root->right == NULL) { // Leaf node
            if (targetSum == currSum + root->val) {
                
                res.push_back(validPath);
                //printVec(validPath);
                //cout << endl;
            }
        }
        
        // Go left, every time account this val for the current path sum
        traverse(root->left, targetSum, currSum + root->val, validPath, res);
        
        // Go right, every time account this val for the current path sum
        traverse(root->right, targetSum, currSum + root->val, validPath, res);
        
        // This is returning path, pop out last item from the path since it was already taken care
        if (!validPath.empty())
            validPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        int currSum = 0;
        
        vector<int> validPath;
        
        traverse(root, targetSum, currSum, validPath, res);
        
        return res;
    }
    
};



/*
Run-Time:


115 / 115 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 19.9 MB
Submitted: 0 minutes ago



*/
