/*
1507. Reformat Date

Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.
 

Example 1:

Input: date = "20th Oct 2052"
Output: "2052-10-20"
Example 2:

Input: date = "6th Jun 1933"
Output: "1933-06-06"
Example 3:

Input: date = "26th May 1960"
Output: "1960-05-26"
 

Constraints:

The given dates are guaranteed to be valid, so no error handling is necessary.

*/

class Solution {
public:
    inline bool isDigit(char c)
    {
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    
    string reformatDate(string date) {
        
        int day;
        int m1;
        int yr;
        
        string sday;
        string smon;
        string syr;
        
        vector<string> months({"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"});
        
        
        if (isDigit(date[0]))
        {
            day = std::stoi(date.substr(0, 1));
            if (isDigit(date[1]))
            {
                day = day * 10 + std::stoi(date.substr(1,1));
            }
        }
        
        if (day > 9)
            sday = to_string(day);
        else
            sday = '0' + to_string(day);
            
        
        
        // Find first space
        int i = 0;
        int n = date.length();
        
        while (i < n)
        {
            if (date[i] == ' ') break;
            i++;
        }
        
        if (i >= n || date[i] != ' ') 
        {
            printf("\n Something is not correct ....");
        }
        else
        {
            string mon = date.substr(i+1, 3);
            int k = 0;
            
            while (k < 12)
            {
                if (mon == months[k]) break;
                k++;
            }
            
            if (k >= 12)
            {
                printf("\nMonth parsing failed ...");
            }
            else
                m1 = k+1;
        }
        
        if (m1 > 9)
            smon = to_string(m1);
        else
            smon = '0' + to_string(m1);
  
  
        // Year
        
        syr = date.substr(i+1+3+1, 4);
        //cout << " YEAR = " << syr;
        
        
        // Now build the result
        
        string res = syr + "-" + smon + "-" + sday;
            
        return res;
        /*
                    Success
            Details 
            Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reformat Date.
            Memory Usage: 6.5 MB, less than 33.69% of C++ online submissions for Reformat Date.
            Next challenge
        */
    }
};
