/* Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not. */

// Difficulty: Easy
// Runtime: 4 ms, faster than 94.65% of C++ online submissions for Palindrome Number.
// Memory Usage: 5.8 MB, less than 84.12% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        int ans = 0;
        int temp = x;
        
        if(x < 0) {
            return false;
        }
        
        while (temp != 0) {
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return false;
            }
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        
        if(x == ans) {
            return true;
        }
        else {
            return false;
        }
    }
};

