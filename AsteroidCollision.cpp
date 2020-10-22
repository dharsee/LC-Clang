/*

Asteroid Collision

Solution
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. 
Asteroids moving the same direction never meet, so no asteroids will meet each other.
 

Constraints:

1 <= asteroids <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
   Hide Hint #1  
Say a row of asteroids is stable. What happens when a new asteroid is added on the right?

*/


class Solution {
public:
    
 
    void reverse(vector<int> &ast)
    {
        int l = 0, h = ast.size() - 1;
        
        while (l < h)
        {
            int t = ast[l];
            ast[l] = ast[h];
            ast[h] = t;
            
            l++;
            h--;
            
        }
    }
    
    // Using stack
    vector<int> collide(vector<int> &ast)
    {
        stack<int> st;
        
        int i, n = ast.size();
        
        for (i = 0; i < n; i++)
        {
            int curr = ast[i];
            
            if (st.empty() || curr > 0)
            {
                st.push(curr);
                continue;
            }
            
            while (true)
            {
                int top = st.top();
                
                if (top < 0)
                {
                    st.push(curr);
                    break; // break while loop
                }
                else if (top == -curr)
                {
                    st.pop();
                    break;
                }
                else if (top > (-curr))
                {
                    break;
                }
                else
                {
                    st.pop();
                    if (st.empty())
                    {
                        st.push(curr);
                        break;
                    }
                }
            } // End of while loop
        } // End of for loop
            
  
        // build result array by scanning stack;
        
        int k = st.size();
        vector<int> res(k, 0);
        
        while (!st.empty())
        {
            res[k-1] = st.top();
            st.pop();
            k--;
        }
        
        //reverse(res);
        
        return res;
    }
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        return collide(asteroids);
    }
    
    /*
    
    275 / 275 test cases passed.
Status: Accepted
Runtime: 24 ms
Memory Usage: 18.2 MB
Submitted: 0 minutes ago
    
    
    
    without res.push();
    275 / 275 test cases passed.
Status: Accepted
Runtime: 20 ms
Memory Usage: 18.1 MB
Submitted: 0 minutes ago

    */
};
