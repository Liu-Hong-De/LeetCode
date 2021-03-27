/* Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:
	1. Read in and ignore any leading whitespace.
	2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
	3. Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
	4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
	5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
	6. Return the integer as the final result. */
	
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 6.9 MB, less than 66.22% of C++ online submissions for String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool negative = false;
        bool begin = false;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 48 && s[i] <= 57) {
                begin = true;
                if(INT_MAX / 10 < ans) {
                    if(negative) {
                        return INT_MIN;
                    }
                    else {
                        return INT_MAX;
                    }
                }
                else if(INT_MAX / 10 == ans) {
                    if(negative) {
                        if(s[i] - '0' >= 8) {
                            return INT_MIN;
                        }
                    }
                    else {
                        if(s[i] - '0' >= 7) {
                            return INT_MAX;
                        }
                    }
                }

                ans = ans * 10 + (s[i] - '0');
            }
            else if(s[i] == 45) {
                if(begin) {
                    break;
                }
                negative = true;
                begin = true;
            }
            else if(s[i] == 43) {
                if(begin) {
                    break;
                }
                begin = true;
            }
            else if(s[i] == 32) {
                if(begin) {
                    break;
                }
            }
            else {
                break;
            }
        }
        
        if(negative) {
            return -1 * ans;
        }
        return ans;
    }
};
