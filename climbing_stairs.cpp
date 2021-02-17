/* You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 5.9 MB, less than 87.79% of C++ online submissions for Climbing Stairs.

class Solution {
public:
    int climbStairs(int n) {
//    	規律剛好等同Fibonacci number 
        if(n == 1) {
            return 1;
        }
        
        int first = 1;
        int second = 2;
        for(int i = 3; i <= n; i++) {
            int ans = first + second;
            first = second;
            second = ans;
        }
        return second;
    }
};
