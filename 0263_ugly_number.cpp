/* An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Ugly Number.
// Memory Usage: 5.8 MB, less than 68.75% of C++ online submissions for Ugly Number

class Solution {
public:
    bool isUgly(int n) {
        while(true) {
            if(n == 0) {
                return false;
            }
            if(n % 2 == 0) {
                n /= 2;
            }
            else if(n % 3 == 0) {
                n /= 3;
            }
            else if(n % 5 == 0) {
                n /= 5;
            }
            else if(n == 1) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};
