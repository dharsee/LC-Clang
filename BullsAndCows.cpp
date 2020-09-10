/*
299. Bulls and Cows

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.


*/
class Solution {
public:
    string getHint(string secret, string guess) {
        
        // Build two frequency tables, one for secret and one for guess
        // scan both the input arguments and compare each position and build 'A' called bulls
        
        // After the scan is complete, tally the frequency table to find 'B' called COWS
        
        int ns = secret.length(), ng = guess.length();
        
        if (ns != ng) return "";
        
        if (secret == guess)
        {
            return to_string(ns)+"A"+to_string(0)+"B";
        }
        
        
        
        
        int acount = 0, bcount = 0;
        
        int i, j;
        
        
        int sfreq[10] = {0}, gfreq[10] = {0}; 
        
        for (i = 0; i < ns; i++)
        {
            if (secret[i] == guess[i]) acount++;
            else
            {
                
                sfreq[secret[i]-'0']++;
                gfreq[guess[i]-'0']++;
            }
        }
        
        // Now Bulls count is confirm
        
        
        string res;
        
        res = to_string(acount)+"A";
        
        // Now build B (Cows) count by scanning two frequency tables
        
        for (i = 0; i < 10; i++)
        {
            if (gfreq[i] > 0 && sfreq[i] > 0)
            {
                if (sfreq[i] >= gfreq[i])
                    bcount += gfreq[i];
                else
                {
                    bcount += sfreq[i];
                }
            }
        }
        
        // Now append Bcount to result
        res += to_string(bcount) + "B";
        
        return res;
        
        
    }
};
