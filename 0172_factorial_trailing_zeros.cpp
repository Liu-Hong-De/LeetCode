// Given an integer n, return the number of trailing zeroes in n!.

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Factorial Trailing Zeroes.
// Memory Usage: 5.7 MB, less than 95.78% of C++ online submissions for Factorial Trailing Zeroes.

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5) {
            if(n % 5 == 0) {
                int temp = n;
                while(temp % 5 == 0) {
                    temp /= 5;
                    count += 1;
                }
                n -= 5;
            }
            else {
             n--;   
            }
        }
        return count;
    }
};
