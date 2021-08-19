/*
N-ary Tree Level Order Traversal

Solution
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 104]

*/



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void __levelOrder(Node *root, vector<vector<int>> &res, int currlevel) {
        
        if (!root) return; // Breaking the recursion
        
        int sz = res.size();
        
        if (currlevel >= sz) {
            res.push_back({root->val});
        } else {
            res[currlevel].push_back(root->val);
        }
        
        int i = 0;
        int nc = root->children.size();
        
        for(i = 0; i < nc; i++)
        __levelOrder(root->children[i], res, currlevel + 1);
        
        
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        
        int currlevel = 0;
        
        __levelOrder(root, res, currlevel);
        
        return res;
    }
};


/*

38 / 38 test cases passed.
Status: Accepted
Runtime: 16 ms
Memory Usage: 11.8 MB
Submitted: 0 minutes ago



*/
