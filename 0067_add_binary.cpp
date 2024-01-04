// Given two binary strings a and b, return their sum as a binary string

// Difficulty: Easy
// Runtime: 4 ms, faster than 67.09% of C++ online submissions for Add Binary.
// Memory Usage: 6.3 MB, less than 82.66% of C++ online submissions for Add Binary.

class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;		// 判斷是否盡為 
        string temp = "";
        
//        令a為字串長度較長的那個以方便後續處理 
        if(a.length() < b.length()) {
            temp = a;
            a = b;
            b = temp;
        }
        
        int al = a.length()-1, bl = b.length()-1;
        
//        先將長度相同的部分相加 
        while(al >= 0 && bl >= 0) {
            if(a[al] == '0' && b[bl] == '0') {
                if(carry) {
                    a[al] = '1';
                    carry = false;
                }
            }
            else if(a[al] == '1' && b[bl] == '1') {
                if(!carry) {
                    a[al] = '0';
                    carry = true;
                }
            }
            else {
                if(carry) {
                    a[al] = '0';
                    carry = true;
                }
                else {
                    a[al] = '1';
                }
            }
            al--;
            bl--;
        }
        
//        再將a剩餘的部分做進位處理 
        while(al >= 0) {
            if(carry) {
                if(a[al] == '1') {
                    a[al] = '0';
                }
                else {
                    a[al] = '1';
                    carry = false;
                }
            }
            al--;
        }
        
//        最前面為兩個1時需再加一位 
        if(carry) {
            a = '1' + a;
        }
        
        return a;
    }
};
