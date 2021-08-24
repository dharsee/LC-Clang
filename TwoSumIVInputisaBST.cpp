/*
Two Sum IV - Input is a BST

Solution
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
Example 3:

Input: root = [2,1,3], k = 4
Output: true
Example 4:

Input: root = [2,1,3], k = 1
Output: false
Example 5:

Input: root = [2,1,3], k = 3
Output: true
 
Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

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
    vector<int> input;
    
    void printVec() {
        auto iter = input.begin();
        
        cout << endl << "Converted Sorted Vector: " << endl;
        while (iter != input.end()) {
            cout << *iter << ", ";
            iter++;
        }
        cout << endl;
    }
    
    // Function to convert BST To Sorted (Ascending Orde) Array
    void traverse(TreeNode* root) {
        if (!root) return;
        
        traverse(root->left);
        input.push_back(root->val);
        traverse(root->right);
    }
    
    bool serach_in_array(int k){
        
        int left = 0, right = input.size() - 1;
        
        while (left < right)
        {
            int curr_sum = input[left] + input[right];
            if (curr_sum == k) return true;
            else if (curr_sum > k) right--;
            else left++;
        }
        
        return false;
        
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        
        traverse(root);
        // printVec();
        
        return serach_in_array(k);
        
    }
};


/*
422 / 422 test cases passed.
Status: Accepted
Runtime: 40 ms
Memory Usage: 36.9 MB
Submitted: 0 minutes ago


N - Number nodes in the BST
Time Complexity = O(N)
Space Complexity = O(N)


*/


/*
using deque container in C++



*/


class Solution {
public:
   
    deque<int> q;
    
    void printQ() {
        std::cout << "mydeque contains:";
  
        for (std::deque<int>::iterator it = q.begin(); it != q.end(); ++it)
            std::cout << ' ' << *it;
        
        std::cout << '\n';
    }
    
    // Function to convert BST To Sorted (Ascending Orde) Array
    void traverse(TreeNode* root) {
        if (!root) return;
        
        traverse(root->left);
        q.push_front(root->val);
        traverse(root->right);
    }
    
    bool serach_in_queue(int k){
        
        //int left = 0, right = input.size() - 1;
        
        while (!q.empty())
        {
            if (q.size() == 1) return false;
            // printQ();
            // Accessing first and last elements from the queue
            int curr_sum = q.front() + q.back();
            
            if (curr_sum == k) return true;
            else if (curr_sum > k) q.pop_front();
            else q.pop_back();
        }
        
        return false;        
    }

    bool findTarget(TreeNode* root, int k) {
        
        traverse(root);
        // printQ();
        if (q.size() == 1) return false;
        return serach_in_queue(k);
        
    }
};

/*
422 / 422 test cases passed.
Status: Accepted
Runtime: 40 ms
Memory Usage: 36.8 MB
Submitted: 0 minutes ago


*/
