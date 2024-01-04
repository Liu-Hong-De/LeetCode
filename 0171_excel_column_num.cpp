/* Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number. */

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 6.3 MB, less than 10.97% of C++ online submissions for Excel Sheet Column Number.

class Solution {
public:
    int titleToNumber(string columnTitle) {
        for(int i = 0; i < columnTitle.length(); i++) {
            ans += pow(26, columnTitle.length()-1-i) * (columnTitle[i]-64);
        }
        return ans;
    }

private:
    int ans = 0;
};
