/*

Expression Add Operators

Solution
Given a string num that contains only digits and an integer target, return all possibilities to add the binary operators '+', '-', or '*' between the digits of num so that the resultant expression evaluates to the target value.

 

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Example 4:

Input: num = "00", target = 0
Output: ["0*0","0+0","0-0"]
Example 5:

Input: num = "3456237490", target = 9191
Output: []
 

Constraints:

1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1
   Hide Hint #1  
Note that a number can contain multiple digits.
   Hide Hint #2  
Since the question asks us to find all of the valid expressions, we need a way to iterate over all of them. (Hint: Recursion!)
   Hide Hint #3  
We can keep track of the expression string and evaluate it at the very end. But that would take a lot of time. Can we keep track of the expression's value as well so as to avoid the evaluation at the very end of recursion?
   Hide Hint #4  
Think carefully about the multiply operator. It has a higher precedence than the addition and subtraction operators.
1 + 2 = 3
1 + 2 - 4 --> 3 - 4 --> -1
1 + 2 - 4 * 12 --> -1 * 12 --> -12 (WRONG!)
1 + 2 - 4 * 12 --> -1 - (-4) + (-4 * 12) --> 3 + (-48) --> -45 (CORRECT!)
   Hide Hint #5  
We simply need to keep track of the last operand in our expression and reverse it's effect on the expression's value while considering the multiply operator.


*/

class Solution {
public:
    vector<string> res;
    
    void dfs(int index, string path, long resSoFar, long prevOperand, string num, int target) {
        
        // Base condition, When you reach lead node of the tree 
        // check for the soFar res with target and add the path to res if matches
        if (index == num.length()) {
            if (resSoFar == target) res.push_back(path);
            return;
        }
        
        // Do the same for rest of the expression, from current index
        for (int i = index; i < num.length(); i++) {
            
            
            
            long currNum = std::stol(num.substr(index, i - index + 1));
            
            //cout <<endl<< "CurrNum = " << currNum << " i = " << i << " Index = " << index << " Path = " << path;
            
            // Skip leading zeros
            if (i > index && num[index] == '0') break;
            
            if (index == 0) { // For the first Operand
                string tpath(""); tpath.append(path); tpath.append(to_string(currNum));
                
                dfs(i + 1, tpath, currNum, currNum, num, target);
                
            } else {
                string tpath("");
                tpath.append(path).append("+").append(to_string(currNum));
                
                //cout << endl << " Add path = " << path << " Tpath = " << tpath << " CurrNum = " << currNum;
                // Rest of the operands, explore with all the possible options, {+, -, *}
                dfs(i + 1, tpath, resSoFar + currNum, 
                    currNum, num, target);
                
                string tpath2(""); tpath2.append(path); tpath2.append("-");
                tpath2.append(to_string(currNum));
                
                //cout << endl << " Subtract path = " << path << " Tpath = " << tpath2;
                dfs(i + 1, tpath2, resSoFar - currNum, 
                    -currNum, num, target);

                string tpath3(""); tpath3.append(path); tpath3.append("*");
                tpath3.append(to_string(currNum));
                
                //cout << endl << " Mul path = " << path << " Tpath = " << tpath3;
                dfs(i + 1, tpath3, 
                    resSoFar - prevOperand + prevOperand * currNum, 
                    currNum * prevOperand, num, target);
                
            }
        }
        
    }
    
    vector<string> addOperators(string num, int target) {
        
        
        
        // Backtracking algorithm to solve this problem
        // Since we need to explore all the possible paths then see if the 
        // current path is a valid solution
        
        //start with 0th index
        dfs(0, "", 0, 0, num, target);
        
        
        return res;
        
    }
};


/*

20 / 20 test cases passed.
Status: Accepted
Runtime: 836 ms
Memory Usage: 132 MB


*/
