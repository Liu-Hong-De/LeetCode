/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
   P   A   H   N
   A P L S I I G
   Y   I   R
   And then read line by line: "PAHNAPLSIIGYIR" */
   
// Runtime: 8 ms, faster than 89.14% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 8.2 MB, less than 88.98% of C++ online submissions for ZigZag Conversion.

class Solution {
public:
    string convert(string s, int numRows) {
        int row = 0;
        int i = 0;
        string ans = "";
        
//        ���u���p 
        if(numRows == 1) {
            return s;
        }
        
        while(ans.length() < s.length()) {
//        	�Y���W�߬�2(n-1) 
            if(row == 0 || row == numRows-1) {
                while(i < s.length()) {
                    ans += s[i];
                    i += 2 * (numRows - 1);
                }
            }
//            �W�߬� 2*(n-1)-�C��*2 �M 2*�C�� 
            else {
                while(i < s.length()) {
                    ans += s[i];
                    i += 2 * (numRows - row - 1);
                    if(i >= s.length()) {
                        break;
                    }
                    ans += s[i];
                    i += 2 * row;
                }
            }
            row++;
            i = row;
        }
        return ans;
    }
};
