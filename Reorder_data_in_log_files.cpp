/*
937. Reorder Data in Log Files

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.

*/

class Solution {
public:
        vector<string> reorderLogFiles2(vector<string>& logs) {
        
        vector<string> res;
        int n = logs.size();
        if (n == 0) return res;
        
        vector<pair<string, string>> letter;
        vector<string> digit;
        
        // Now break the logs into temp as <<log> <identifier>>
        // Sort and then re-construct back to <identifier log> structrure
        
        // Break 
        int i = 0;
        while (i < n)
        {
            int k = 0; 
            
            while (logs[i][k] != ' ') // To find first word
                k++;
            string id = logs[i].substr(0, k);
            string log = logs[i].substr(k+1); 
            
            // To find first char in the log part to group into {Letters OR Digits}
            k = 0;
            while (log[k] == ' ') k++;
            
            if (log[k] >= '0' && log[k] <= '9')
                digit.push_back(logs[i]);
            else
                letter.push_back({log, id});
            
            i++;
        }
        
        sort(letter.begin(), letter.end());
        
        // Stitch back  
        i = 0;
        n = letter.size();
        while (i < n)
        {
            res.push_back(letter[i].second + " " + letter[i].first);
            i++;
        }
        
        i = 0;
        n = digit.size();
        while (i < n)
        {
            res.push_back(digit[i]);
            i++;
        }
    
        return res;
    }
    
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> res;
        int n = logs.size();
        if (n == 0) return res;
        
        vector<pair<string, string>> letter;
        
        //We dont need to copy digit string, just remember its index to optimize space
        vector<int> indices;
        
        // Now break the logs into temp as <<log> <identifier>>
        // Sort and then re-construct back to <identifier log> structrure
        
        // Break 
        int i = 0;
        while (i < n)
        {
            int k = 0; 
            
            while (logs[i][k] != ' ') // To find first word
                k++;
            
            string id = logs[i].substr(0, k);
            string log = logs[i].substr(k+1); 
            
            // To get first letter/digit from log after identifier to decide whether its belongs to digit gropu or letter
            k = 0;
            while (log[k] == ' ') k++;
            
            if (log[k] >= '0' && log[k] <= '9')
                indices.push_back(i);
            else
                letter.push_back({log, id});
            
            i++;
        }
        
        sort(letter.begin(), letter.end());
        
        // Stitch back  
        i = 0;
        n = letter.size();
        while (i < n)
        {
            res.push_back(letter[i].second + " " + letter[i].first);
            i++;
        }
        
        // Append Digits logs
        i = 0;
        n = indices.size();
        while (i < n)
        {
            res.push_back(logs[indices[i]]);
            i++;
        }
        
        return res;
        
    }
};
