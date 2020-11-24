/*
Unique Morse Code Words

Solution
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.

*/


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int res = 0;
        
        std::string ref[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // Initialize vector with a string array
        std::vector<std::string> vecOfStr(ref, ref + sizeof(ref)/sizeof(std::string));
        
        int i = 0;
        
        int n = vecOfStr.size();
        while (i < n)
        {
            cout << i << "  ==>  " << vecOfStr[i] << endl;
            i++;
        }
        
        
        //maintain set to hold unique elements
        
        set<string> res_set;
        
        //scan input vect
        n = words.size();
        
        for (i = 0; i < n; i++)
        {
            string curr_str = "";
            
            int j = 0;
            int k = words[i].length();
            
            while (j < k)
            {
                curr_str += vecOfStr[words[i][j] - 'a'];
                j++;
            }
            
            res_set.insert(curr_str);
        }
        
        
        
        res = res_set.size();
        return res;
        
        
        /*
                    83 / 83 test cases passed.
            Status: Accepted
            Runtime: 8 ms
            Memory Usage: 9.2 MB
            Submitted: 0 minutes ago

        */
    }
};
