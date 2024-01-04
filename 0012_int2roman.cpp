/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is
simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not 
IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. */

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer to Roman.
// Memory Usage: 5.9 MB, less than 82.68% of C++ online submissions for Integer to Roman.

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int count = 0;		// ¦ì¼Æ 
        
        while(num > 0) {
            int temp = num % 10;
            if(temp == 4) {
                if(count == 0) {
                    ans += "IV";
                }
                else if(count == 1) {
                    ans = "XL" + ans;
                }
                else if(count == 2) {
                    ans = "CD" + ans;
                }
            }
            else if(temp == 9) {
                if(count == 0) {
                    ans += "IX";
                }
                else if(count == 1) {
                    ans = "XC" + ans;
                }
                else if(count == 2) {
                    ans = "CM" + ans;
                }
            }
            else if(temp >= 5) {
                while(temp - 5 != 0) {
                    if(count == 0) {
                        ans += "I";
                    }
                    else if(count == 1) {
                        ans = "X" + ans;
                    }
                    else if(count == 2) {
                        ans = "C" + ans;
                    }
                    temp--;
                }
                
                if(count == 0) {
                    ans = "V" + ans;
                }
                else if(count == 1) {
                    ans = "L" + ans;
                }
                else if(count == 2) {
                    ans = "D" + ans;
                }
            }
            else {
                while(temp != 0) {
                    if(count == 0) {
                        ans += "I";
                    }
                    else if(count == 1) {
                        ans = "X" + ans;
                    }
                    else if(count == 2) {
                        ans = "C" + ans;
                    }
                    else if(count == 3) {
                        ans = "M" + ans;
                    }
                    temp--;
                }
            }
            
            num /= 10;
            count++;
        }
        return ans;
    }
};
