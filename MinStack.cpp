/*

155. Min Stack
Easy

6514

549

Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/



/*

2 Solutions 

1.
Let's maintain stack data structure to hold items but with pairs
pair<int, int> ---> denotes <item, min_so_far>

Push - will add item to stack and also update the min if needed.
pop - will remove the top item and gets the next min item 


*/


class MinStack {
public:
    
    stack <pair<int, int>> st;
    int currMin = INT_MAX;
    
    MinStack() {
        currMin = INT_MAX;
    }
    
    void push(int val) {
        
        if (currMin > val) {
            st.push({val, val});
            currMin = val; // Just to track
        } else {
            st.push({val, currMin});
        }
    }
    
    void pop() {
        
        if (st.empty()) return;
        
        st.pop();
        
        currMin = st.empty() ? INT_MAX : st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        
       return currMin;
    
    }
};

/*

// 2.
// This is brute force method and takes more time and space 



class MinStack {
public:
    
    
    #define SZ (10*1024)
    
    struct obj_s {
        int arr[SZ];
        int top;
        int minInd;
    };
    
    typedef struct obj_s obj_t;
    
    obj_t obj;
    
    MinStack() {
        obj.top = -1;
        obj.minInd = -1;
    }
    
    void push(int val) {
        
        if (obj.top >= SZ) {
            cout <<endl << " Overflow condition met";
            return;
        }
        
        obj.top++;
        obj.arr[obj.top] = val;
        
        if (obj.minInd == -1) {
            obj.minInd = obj.top;
            return;
        }
        
        if (obj.arr[obj.minInd] > val) {
            obj.minInd = obj.top;
        }
        
    }
    
    void pop() {
        
        if (obj.top < 0) {
            cout << endl << "Underflow condition Occured";
            return;
        }
        
        //check for rescanning to find current min
        if (obj.minInd == obj.top) {
            int i;
            obj.minInd = 0;
            for (i = 1; i < obj.top; i++) {
                if (obj.arr[obj.minInd] > obj.arr[i]) {
                    obj.minInd = i;
                }
            }
        }
        
        // decrement
        obj.top--;
        if (obj.top == -1) obj.minInd = -1;
    }
    
    int top() {
        if (obj.top < 0) {
            cout << endl << " Empty Stack ... ";
            return -1;
        }
        return obj.arr[obj.top];
    }
    
    int getMin() {
        
        if (obj.minInd < 0) {
            cout << endl << " Empty Stack ... ";
            return -1;
        }
        return obj.arr[obj.minInd];
    
    }
};
*/



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
