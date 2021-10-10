// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

// Runtime: 8 ms, faster than 74.60% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 6 MB, less than 30.76% of C++ online submissions for Bitwise AND of Numbers Range.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        int ans = 0;
        
        while(left > 0 && right > 0 && left != right) {
            count++;
            left /= 2;
            right /= 2;
        }
        if(left == right) {
            ans = left * pow(2, count);
        }
        
        return ans;
    }
};
