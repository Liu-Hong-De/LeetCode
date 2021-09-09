/* Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:
Note that in some languages, such as Java, there is no unsigned integer type. 
In this case, the input will be given as a signed integer type. 
It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 3, the input represents the signed integer. -3. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 5.8 MB, less than 78.79% of C++ online submissions for Number of 1 Bits.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t temp = n;
        
//        ¥k²¾32bit 
        for(int i = 0; i < 32; i++) {
            if(temp & 1 == 1) {
                ans += 1;
            }
            temp = temp >> 1;
        }
        return ans;
    }
};
