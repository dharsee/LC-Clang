/*
382. Linked List Random Node
Medium


Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
 
 
 // In this solution I am using O(N) memeory to store list elements.
 
class Solution {
    vector<int> vect;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        
        while (head)
        {
            vect.push_back(head->val);
            head = head->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        int index = rand() % vect.size();
        return vect[index];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
 
 
 /*
 Success
Details 
Runtime: 52 ms, faster than 44.83% of C++ online submissions for Linked List Random Node.
Memory Usage: 17 MB, less than 9.34% of C++ online submissions for Linked List Random Node.
 
 
 */
