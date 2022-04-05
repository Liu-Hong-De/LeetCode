// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.9 MB, less than 81.52% of C++ online submissions for Pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        double ans = x;
        int count = 1;
        bool negative = false;
        
//        special case
        if(x == 1 || (x == -1 && n % 2 == 0)) {
            return 1;
        }
        else if(x == -1 && n % 2 == 1) {
            return -1;
        }
        else if(n == INT_MIN) {
            return 0;
        }
        
        if(n < 0) {
            negative = true;
            n = abs(n);
        }
        
//        use the power of 2 to calculate more quickly
        if(n > 0) {
            while(count < n/2) {
                ans *= ans;
                count *= 2;
            }
            n -= count;
            ans *= myPow(x, n);
        }
        else {
            return 1;
        }
        
        if(flag) {
            return 1/ans;
        }
        return ans;
    }
};
