// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Digits.
// Memory Usage: 5.7 MB, less than 96.07% of C++ online submissions for Add Digits.

class Solution {
public:
    int addDigits(int num) {
        int ans = num;
        while(num > 9) {
            ans = 0;
            while(num > 0) {
                ans += num % 10;
                num /= 10;
            }
            num = ans;
        }
        return ans;
    }
};
