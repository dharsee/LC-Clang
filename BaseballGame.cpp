/*

682. Baseball Game

You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.

*/

class Solution {
    
    inline int strToInt(string s)
    {
        int n = s.length();
        int i, num = 0;
        bool neg = false;
        int start = 0;
        
        
        if (n <= 0) return -1;
        
        if (s[0] == '-')
        {
            neg = true;
            start = 1;
        }
        
        if (s[start] >= '0' && s[start] <= '9')
            num = s[start] - '0';
        else
            return -1;
        
        
        for (i = start+1; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num = (num * 10) + s[i] - '0';
            else
                return -1;
        }
       
        if (neg) num = -num;
        return num;
    }
    
public:
    int calPoints(vector<string>& ops) {
        
        int total = 0;
        int last_1 = 0, last_2 = 0; // these two will
        int num = 0;
        
        stack<int> st;
        
        int n = ops.size();
        int i = 0;
        while (i < n)
        {
            if (ops[i] == "D")
            {
                if (!st.empty())
                {
                    int curr_round = 2*st.top();
                    total += curr_round;
                    st.push(curr_round);
                }
            }
            else if (ops[i] == "+")
            {
                if (!st.empty())
                {
                    int t1 = st.top(), t2 = 0;
                    st.pop();
                    
                    if (!st.empty())
                    {
                        t2 = st.top();
                    }
                    else
                    {
                        printf("\n There Were no 2 previous valid scores ... ");
                    }
                    
                    int curr_score = t1 + t2;
                    
                    total += curr_score;
                    
                    st.push(t1);
                    st.push(curr_score);
                }
                else
                    printf("\n + :- Why Stack is empty ??? ");
                
            }
            else if (ops[i] == "C")
            {
                if (!st.empty())
                {
                    int last_valid = st.top();
                    st.pop();
                    
                    total -= last_valid;
                }
                else
                    printf("\n C :- Why stack is empty ??? ");
            }
            else if ((num = strToInt(ops[i])) != -1)
            {
                total += num;
                st.push(num);
            }
            else
            {
                cout << "\nWhy this is not known option ???? '" << ops[i] << "'";
            }
            
            
            i++;
            //printf("\n Round %d : Total = %d ", i, total);
        } // End of while loop
        
        return total;
    }
};

/*


39 / 39 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 8.5 MB
Submitted: 2 minutes ago


*/
