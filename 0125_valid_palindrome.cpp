// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 

// Difficulty: Easy
// Runtime: 3 ms, faster than 95.51% of C++ online submissions for Valid Palindrome.
// Memory Usage: 7.3 MB, less than 87.92% of C++ online submissions for Valid Palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j) {
            if(!((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90) || (97 <= s[i] && s[i] <= 122))) {
                i++;
            }
            else if(!((48 <= s[j] && s[j] <= 57) || (65 <= s[j] && s[j] <= 90) || (97 <= s[j] && s[j] <= 122))) {
                j--;
            }
            else {
                if(!((s[i] >= 65 && s[j] >= 65 && (s[i] + 32 == s[j] || s[i] - 32 == s[j])) || s[i] == s[j])) {
                    return false;
                }
                else {
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};
