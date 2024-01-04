/* Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [-23^1, 2^31 - 1]. 
For this problem, assume that your function returns 2^31 - 1 when the division result overflows. */

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
// Memory Usage: 5.8 MB, less than 76.34% of C++ online submissions for Divide Two Integers.

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if(dividend == 0 || (divisor == INT_MIN && dividend != INT_MIN)) {
            return 0;
        }
        if(abs(divisor) == 1) {
            return positive ? abs(dividend) : ~abs(dividend)+1;
        }
        if(abs(divisor) == dividend) {
            return positive ? 1 : -1;
        }
        
        bool special = false;
        if(dividend == INT_MIN) {
            special =  true;
            dividend = INT_MAX;
        }
        
        int quotient = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        while(dividend - divisor >= 0) {
            int count = 0;
            int shift_divisor = divisor << 1;
            while(dividend > shift_divisor && shift_divisor < INT_MAX >> 1 + 1 && shift_divisor > 0) {
                count++;
                shift_divisor = shift_divisor << 1;
            }
            int temp = 1 << count;
            quotient += temp;
            temp = divisor << count;
            dividend -= temp;
            
        }
        cout << quotient << endl;
        if(special && dividend+1 == divisor) {
            quotient++;
        }
        if(!positive) {
            quotient = ~quotient+1;
        }
        return quotient;
    }
};
