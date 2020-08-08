/*
Path Sum III

Solution
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

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
    
    // Basically we are traversing tree 2 times
    // one time is with root node val
    // second time is without root node val
    
    int traverse(TreeNode* root, int sum) {
        
        if (!root) return 0;
    
        int count = 0;
        if (root->val == sum) count++;
        
        count += traverse(root->left, sum - root->val);
        count += traverse(root->right, sum - root->val);
        
        return count;
    }
        
    
    // Recursive solution with O(1) space complexity
    
    int pathSum(TreeNode* root, int sum) {
        
        if (!root) return 0;
        
        return pathSum(root->left, sum) +
                pathSum(root->right, sum) +
                traverse(root, sum);
        
    }


    
    
    #if 0
    // This has runtime : O(N) and Space complexity O(N), this is due to list/vector and recursion
    // recursion can be ignored for this now
    void traverse(TreeNode *root, int sum, int &count, vector<int> &path)
    {
        // Base condition for recursion
        if (!root) return;
        
        // Add this node val to the vector
        path.push_back(root->val);
        
        // Do the same for left and right sub trees
        
        traverse(root->left, sum, count, path);
        traverse(root->right, sum, count, path);
        
        // Now we are done with left and right sub tree
        // we have path, see if this node is making a solution or not
        // and then remove it
        
        int tsum = 0;
        for (int i = path.size() - 1; i >= 0; --i)
        {
            tsum += path[i];
            if (tsum == sum)
                count++;
        }
        
        // Remove this node val from the list
        /*
        auto iter = path.rbegin();
        path.erase(iter);
        */
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int sum) {
        
        vector<int> path;
        int count = 0;
        traverse(root, sum, count, path);
        
        return count;
    }
    #endif
};
