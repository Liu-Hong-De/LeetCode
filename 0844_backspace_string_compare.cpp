/* Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty. */

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6 MB, less than 97.67% of C++ online submissions for Backspace String Compare.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_ptr = s.length() - 1;
        int t_ptr = t.length() - 1;
        
        while(s_ptr >= 0 || t_ptr >= 0) {
            int skip = 0;
            while(s_ptr >= 0) {
                if(s[s_ptr] == '#') {
                    skip++;
                    s_ptr--;
                }
                else if(skip > 0) {
                    skip--;
                    s_ptr--;
                }
                else {
                    break;
                }
            }
            skip = 0;
            while(t_ptr >= 0) {
                if(t[t_ptr] == '#') {
                    skip++;
                    t_ptr--;
                }
                else if(skip > 0) {
                    skip--;
                    t_ptr--;
                }
                else {
                    break;
                }
            }
            
//            check this position is equal or not
            if(s_ptr >= 0 && t_ptr >= 0 && s[s_ptr] != t[t_ptr]) {
                return false;
            }
            
//            avoid to compare character and null
            if((s_ptr >= 0) != (t_ptr >= 0)) {
                return false;
            }
            
            s_ptr--;
            t_ptr--;
        }
        return true;
    }
};
