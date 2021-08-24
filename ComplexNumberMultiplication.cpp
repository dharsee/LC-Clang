/*
Complex Number Multiplication

Solution
A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

 

Example 1:

Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:

Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 

Constraints:

num1 and num2 are valid complex numbers.

*/


class Solution {
public:
    void extract(string &input, int &real, int &imaginary) {
        
        bool real_is_complete = false;
        bool real_is_negative = false;
        
        bool img_is_negative = false;
        
        int i = 0;
        int sz  = input.length();
        int res = 0;
        
        if (sz == 0) return;
        
        real_is_negative = (input[0] == '-') ? true : false;
        
        if (real_is_negative) i++;
        
        // "1+1i"
        while (i < sz) {
            
            if (input[i] == '+') { real = res; res  = 0; real_is_complete = true; i++; continue; }
            
            if (input[i] == '-') { img_is_negative = true; i++; continue; }
            
            if (input[i] >= '0' && input[i] <= '9') {
                res = res * 10;
                res = res + input[i] - '0';
                // cout << endl << "got the real val = " << input[i] << "  RES = " << res;
            } 
            /*
            else {
                cout << endl << "Something is not correct = " << input[i];
            }
            */
            i++;
        }

        // Whatever present in res must be imaginary part;
        // imaginary = res ? res : 1;
        imaginary = res;
        if (real_is_negative) real = -real;
        if (img_is_negative) imaginary = -imaginary;
    }
    
    string complexNumberMultiply(string num1, string num2) {
        
        // extract real numbers and imaginary numbers
        int real1 = 0, real2 = 0, img1 = 0, img2 = 0;
        
        extract(num1, real1, img1);
        extract(num2, real2, img2);
        
        /*
        cout << endl << "Real1 = " << real1 << " Img1 = " << img1;
        cout << endl << "Real2 = " << real2 << " Img2 = " << img2 << endl;
        */  
        
        // Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
        int real_res = real1 * real2;
        int img_res  = img1 * img2;
        
        int t1 = real1 * img2;
        int t2 = real2 * img1;
        
        img_res = -1 * (img_res);
    
        int part1 = real_res + img_res;
        int part2 = t1 + t2;
        
        /*
        cout << endl << "REAL = " << real_res << "  IMG = " << img_res;
        cout << endl << "T1 = " << t1 << " T2 = " << t2 << " PART1 = " << part1 << " PART2 = " << part2;
        */
        
        string res_str;
        
        res_str.append(part1 == 0 ? "0" : to_string(part1)); 
        res_str.append("+");
        res_str.append(part2 == 0 ? "0" : to_string(part2));
        res_str.append("i");
        
        return res_str;
        
    }
};

/*
55 / 55 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 6 MB
Submitted: 0 minutes ago

*/
