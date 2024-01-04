/* Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned. */

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
// Memory Usage: 5.8 MB, less than 81.91% of C++ online submissions for Sqrt(x).

class Solution {
public:
    int mySqrt(int x) {
        int mid = x;
        int high = x;
        int low = 0;
        
        if(x == 0) {
            return 0;
        }
        
//        §Q¥Îbinary searcuªº·§©À¥h¹Gªñµ²ªG 
        while(1) {
            if(x / mid > mid) {
                low = mid;
                mid = low + (high-low) / 2;
            }
            else if(x / mid < mid) {
                high = mid;
                mid /= 2;
            }
            else {
                return mid;
            }
            
            if(high - low == 1) {
                return low;
            }
        }
    }
};
