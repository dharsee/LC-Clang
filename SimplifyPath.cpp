/*
Simplify Path

Solution
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: path = "/a/./b/../../c/"
Output: "/c"
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.

*/

class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.length();
        if (n == 0 || n == 1) return "/";
        
        
        // work with string methods, find and substr
        // maintain stack and perform the push and pop according to the input token
        
        stack<string> st;
        
        int start = 0;
        int end = path.find("/");
        
        string last_token = "";
                
        while(end != std::string::npos)
        {
            string curr_token = path.substr(start, end-start);
            // cout << "Current token  [" << curr_token << "]"; 
            
            if (curr_token == ".") // Nothing to do, contiunue
            {
                // cout << " Nothing ";
                ;
            }
            else if (curr_token == "..") // Pop top element on the stock
            {
                // cout << " Popping out top ";
                if (!st.empty()) st.pop();
            }
            else if(curr_token.length() > 0) // Assuming valid dir name other than special chars
            {
                // cout << "Adding ";
                st.push(curr_token);
            }
            
            cout << endl;
            start = end + 1; // 1 - for delimiter
            end = path.find("/", start);

        }
        
        //check for last token which was unclosed
        //if (end == std::string::npos) // means we reached end, just check the last word
        int len = n - start;
        if (len > 0) last_token = path.substr(start, len);  
        
        // cout << "Last Token str = {" << last_token << "}";
        
        if (last_token.length() > 0)
        {
            if (last_token == ".."){
                if (!st.empty()) st.pop();
            }
            else if (last_token == ".")
                int x = 2; // Doing nothing
            else st.push(last_token);
        }
        
        
        // Build the result path;
        string res = "/";
        int i = 0;
        if (!st.empty()) {
            res = res + st.top();
            st.pop();
        }
        
        // cout << "Before Loop str = " << res;
        
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res;
        
        /*
        256 / 256 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 10.7 MB
        */
        
    }
};

