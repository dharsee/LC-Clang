/*
Verify Preorder Serialization of a Binary Tree

Solution
One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.


For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.

 

Example 1:

Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: preorder = "1,#"
Output: false
Example 3:

Input: preorder = "9,#,#,1"
Output: false
 

Constraints:

1 <= preorder.length <= 104
preorder consist of integers in the range [0, 100] and '#' separated by commas ','.

*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        vector<string> nodes;
        
               
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = preorder.find(delimiter)) != std::string::npos) {
            token = preorder.substr(0, pos);
            nodes.push_back(token);
            //std::cout << token << std::endl;
            preorder.erase(0, pos + delimiter.length());
        }
        nodes.push_back(preorder);
        int i, sz = nodes.size();
        
       // cout << endl << " Sz = " << sz  << endl;
        
        int diff = 1;
        for (i = 0; i < sz; i++)
        {
            if (--diff < 0) return false;
            
            if (nodes[i].compare("#")) diff += 2;
        }
        
        //cout << endl << " Sz = " << sz << " Diff =  " << diff << endl;
        
        return diff == 0;
        
    }
};


/*
151 / 151 test cases passed.
Status: Accepted
Runtime: 20 ms
Memory Usage: 9.7 MB
Submitted: 0 minutes ago
*/
