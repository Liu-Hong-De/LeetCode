// Given two binary strings a and b, return their sum as a binary string

// Runtime: 4 ms, faster than 67.09% of C++ online submissions for Add Binary.
// Memory Usage: 6.3 MB, less than 82.66% of C++ online submissions for Add Binary.

class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;		// �P�_�O�_�ɬ� 
        string temp = "";
        
//        �Oa���r����׸��������ӥH��K����B�z 
        if(a.length() < b.length()) {
            temp = a;
            a = b;
            b = temp;
        }
        
        int al = a.length()-1, bl = b.length()-1;
        
//        ���N���׬ۦP�������ۥ[ 
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
        
//        �A�Na�Ѿl���������i��B�z 
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
        
//        �̫e�������1�ɻݦA�[�@�� 
        if(carry) {
            a = '1' + a;
        }
        
        return a;
    }
};
