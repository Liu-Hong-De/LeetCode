/* Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself. */

// Runtime: 4 ms, faster than 51.43% of C++ online submissions for Plus One.
// Memory Usage: 8.8 MB, less than 83.73% of C++ online submissions for Plus One.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp = digits.size()-1;
        
        while(temp >= 0) {
            if(digits[temp] == 9) {
                digits[temp] = 0;
            }
            else {
                digits[temp]++;
                return digits;
            }
            temp--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
