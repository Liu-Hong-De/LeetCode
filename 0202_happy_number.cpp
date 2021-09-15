/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 5.7 MB, less than 95.40% of C++ online submissions for Happy Number.

class Solution {
public:
    bool isHappy(int n) {
        while(n != 1 && n != 4) {
            n = next(n);
        }
        return (n==1);
    }
    
    int next(int n) {
        int num = 0;
        while(n) {
            num += pow(n % 10, 2);
            n /= 10;
        }
        return num;
    }
};
