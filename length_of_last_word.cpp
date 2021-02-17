/* Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
A word is a maximal substring consisting of non-space characters only. */

// Runtime: 4 ms, faster than 59.13% of C++ online submissions for Length of Last Word.
// Memory Usage: 6.5 MB, less than 56.02% of C++ online submissions for Length of Last Word.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool flag = false;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                flag = true;
            }
            else if(s[i] != ' ' && flag) {
                ans = 1;
                flag = false;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
}; 
