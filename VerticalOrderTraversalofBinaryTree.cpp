/*
Vertical Order Traversal of a Binary Tree

Solution
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

Example 1:

Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

Example 2:

Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 

Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.

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
    
    void traverse(TreeNode *root, int col, int row, unordered_map<int, vector<pair<int, int>>> &hmap,
                 int &minC, int &maxC)
    {
        if (!root) return;
        
        auto iter = hmap.find(col);
        if (iter != hmap.end()) // FOUND
        {
            //printf("\n Found adding %d ", root->val);
            vector<pair<int, int>> t;
            
            t = iter->second;
            //printf(" Size = %d", t.size());
            t.push_back({row, root->val});
            //printf(" Post Size = %d", t.size());
            
            iter->second = t;
        }
        else
        {
            vector<pair<int, int>> t;
            
            t.push_back({row, root->val});
            
            hmap[col] = t;
        }
        
        if (minC > col) minC = col;
        if (maxC < col) maxC = col;
        
        // DO it for left sub tree and right sub tree
        
        traverse(root->left, col - 1, row + 1, hmap, minC, maxC);
        traverse(root->right, col + 1, row + 1, hmap, minC, maxC);
        
    }
    
    void dump(unordered_map<int, vector<pair<int, int>>> &hmap)
    {
        auto iter = hmap.begin();
        
        while (iter != hmap.end())
        {
            printf ("\n %d -> ", iter->first);
            vector<pair<int, int>> t;
            t = iter->second;
            int j = 0, k = t.size();
            //printf(" j = %d k = %d ", j, k);
            while (j < k)
            {
                printf(" {%d %d}", t[j].first, t[j].second);
                j++;
            }
        
            iter++;
        }
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        if (!root) return res;
        
        // Define DS to have mapping of col and row with its node val
        
        unordered_map<int, vector<pair<int, int>>> hmap;
        // <Col, <row, nodeval>>
        
        int minC = 0, maxC = 0;
        
        traverse(root, 0, 0, hmap, minC, maxC); // root, Col, Row
        
        /*
        printf("\n minC = %d maxC = %d ", minC, maxC);
        dump(hmap);
        */
        
        
        
        int i = 0;
       
        for (i = minC; i <= maxC; i++)
        {
            // Sort as per requirement, regular sorting will not solve the problem
            // Sort based on rows, and when that are more values in the same row, sort based on the values
            sort(hmap[i].begin(), hmap[i].end(), [](pair<int, int> &p1, pair<int, int> &p2){
                return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });
            
            vector<int> col;
            
            for (pair<int, int> &p : hmap[i])
                col.push_back(p.second);
            
            res.push_back(col);
        }
        return res;
        
        
        /*
        //printf(" \n Post process :\n");
        for (i = minC; i <= maxC; i++)
        {
            //printf("\n i = %d", i);
            auto iter = hmap.find(i);
            
            if (iter != hmap.end()) // FOUND
            {
                vector<pair<int, int>> t;
                t = iter->second;
                int j = 0, k = t.size();
                
                vector<int> sameRow;
                //printf(" j = %d k = %d ", j, k);
                while (j < k)
                {
                    sameRow.push_back(t[j].second);
                    //printf(" {%d %d}", t[j].first, t[j].second);
                    j++;
                }
                
                if (sameRow.size() > 1)
                {
                    sort(sameRow.begin(), sameRow.end());
                    res.push_back(sameRow);
                }
                else
                {
                    res.push_back(sameRow);
                }
                
            }
        }
        return res;
        */
        
        
        
        
        
        
    }
};
