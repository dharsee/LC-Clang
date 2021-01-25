/*

Merge k Sorted Lists

Solution
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

*/


// Method #1
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
class Solution {
public:
    
    // There are couple of alogirthms to solve this problem
    // Algo #1. 
    // Add headers of each list in the queue and pick(remove) two lists and Merge them in one then 
    // append result to the tail of the queue
    // Repeate the same process until you see single head in the queue
    // Time Complexity would be O(n log k)
    
    
    ListNode *Merge(ListNode *l1, ListNode *l2) {
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *temp = new ListNode(0); // Dummy
        ListNode *ret = temp;
        
        while (l1 && l2)
        {
            if (l1->val <= l2->val){ temp->next = l1; l1 = l1->next; }
            else { temp->next = l2; l2 = l2->next; }
            
            temp = temp->next;
        }
        
        // Left over from either L1 or L2, if any
        if (l1) temp->next = l1;
        else if (l2) temp->next = l2;

        return ret->next;
    }
    
    void print_list(ListNode *list)
    {
        printf("\n");
        while (list)
        {
            printf(" %d ->", list->val);
            list = list->next;
        }
        
        printf("\n");
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        int i = 0;
        
        if (n == 0) return NULL;
        
        // Maintain queue to hold 
        queue <ListNode *> q;
        
        // Add headers of each list into queue
        
        while (i < n)
        {
            q.push(lists[i]);
            i++;
        }
        
        
        int qsz = q.size();
        
        while (q.size() > 1)
        {
            // Pick two elements from the queue and perform merge 
            
            ListNode *l1 = q.front();
            q.pop();
            ListNode *l2 = q.front();
            q.pop();
            
            // Merge these two into one
            ListNode *res = Merge(l1, l2);
            //print_list(res);
            q.push(res);
        }
        
        return q.front();
        
    }
}; 



// Method 2: Using Recurson

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
class Solution {
public:
   
    // Method #2 - Using recurson
    
    
    ListNode *Merge(ListNode *l1, ListNode *l2) {
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *temp = new ListNode(0); // Dummy
        ListNode *ret = temp;
        
        while (l1 && l2)
        {
            if (l1->val <= l2->val){ temp->next = l1; l1 = l1->next; }
            else { temp->next = l2; l2 = l2->next; }
            
            temp = temp->next;
        }
        
        // Left over from either L1 or L2, if any
        if (l1) temp->next = l1;
        else if (l2) temp->next = l2;

        return ret->next;
    }
    
    void print_list(ListNode *list)
    {
        printf("\n");
        while (list)
        {
            printf(" %d ->", list->val);
            list = list->next;
        }
        
        printf("\n");
        
    }
    
    
    ListNode *MergeKList(vector<ListNode *> &lists, int left, int right){
        if (left > right) return NULL;
        
        if (left == right) return lists[left];
        
        int mid = (right - left) / 2 + left;
        
        ListNode *L1 = MergeKList(lists, left, mid);
        ListNode *L2 = MergeKList(lists, mid + 1, right);
        
        return Merge(L1, L2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        int i = 0;
        
        if (n == 0) return NULL;
 
        return MergeKList(lists, 0, n - 1);
           
    }
}; 



// Method #3 - Using Priority Queues 
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
class Solution {
public:
   
    // Method #3 - using Priority Queue
    

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        
        int n = lists.size();
        int i = 0;
        
        if (n == 0) return NULL;
 
        // Define elements mapping with its value
        typedef pair<int, ListNode*> ele;
        
        // Define Priority Queue on this new data type
        priority_queue<ele> pq;
        
        
        // Dummy node and maintain iterator node
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        
        // Add headers of the each list into priority Queue
        
        while (i < n)
        {
            // This check is needed to skip adding empty list to priority Queue 
            if (lists[i]) pq.push(make_pair(-lists[i]->val, lists[i])); // Negative is to make it ascending order
            i++;
        }
        
        // Now pick top element from the pq and append it to the curr
        
        while (!pq.empty())
        {
            ListNode *t = pq.top().second;
            pq.pop();
            
            curr->next = t;
            curr = curr->next;
            
            // Now add t->next to the PQ back, it will get its spot in the PQ
            if (t->next)
            {
                pq.push(make_pair(-t->next->val, t->next));
            }
            
        }
        
        return dummy->next;
        

    }
}; 
