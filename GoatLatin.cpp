/*
Goat Latin

Solution
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.

*/

class Solution {
public:
    
    inline bool isLower(char ch)
    {
        return (ch >= 'a' && ch <= 'z') ? true : false;
        
    }
    
    inline bool isUpper(char ch)
    {
        return (ch >= 'A' && ch <= 'Z') ? true : false;
    }
    
    bool isVowel(char ch)
    {
        switch(ch)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': return true;
            default: return false;
        }
        
        return false;
    }
    
    string toGoatLatin(string S) {
        
        int nw = 1;
        int i;
        int n = S.length();
        char first_char;
        
        string res = "";
        
        //Assume that first char wont be a space
        i = 0;
        
        while (S[i] == ' ') i++;
        
        first_char = S[i++];
        
        //start with second char
        
        bool needToappend = false;
        if (!isVowel(first_char))
        {
            needToappend = true;
        }
        else
            res = first_char;
        
        //printf("\n first char [%c] append [%d]", first_char, needToappend);
        
        bool first_char2 = false;
        while (i < n)
        {
            if (S[i] == ' ')
            {
                int k = 0;
                
                if (needToappend) {
                    res += first_char;
                    needToappend = false;
                }
                
                res += "ma";
                
                string t(nw, 'a');
                res += t;
                /*
                while (k < nw)
                {
                    res += 'a';
                    k++;
                }
                */
                
                res += ' ';
                
                nw++;
                first_char2 = true;
            }
            else
            {
                if (!first_char2)
                    res += S[i];
                else
                {
                    
                    if (isVowel(S[i]))
                    {
                        res += S[i];
                        needToappend = false;
                    }
                    else
                    {
                        first_char = S[i];
                        needToappend = true;
                    }
                    
                    first_char2 = false;
                    //printf("\n i = %d first char [%c] append [%d]", i, first_char, needToappend);
                }
            }
            i++;
        }
        
        
        // Handle Last word ending
        int k = 0;
                
        if (needToappend) {
            res += first_char;
            needToappend = false;
        }
                
        res += "ma";
        
        
        string t(nw, 'a');
        res += t;
        
        /*
        
        while (k < nw)
        {
            res += 'a';
            k++;
        }
        */
        
        
        
        return res;
    }
};
