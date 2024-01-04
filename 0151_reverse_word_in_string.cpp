/* Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces. */ 

// Difficulty: Medium
// Runtime: 7 ms, faster than 46.61% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 20.8 MB, less than 25.81% of C++ online submissions for Reverse Words in a String.

class Solution {
public:
    string reverseWords(string s) {
        bool flag = false;
        string ans = "";
        string temp = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                flag = true;
                continue;
            }
            if(flag && temp != "" && s[i] != ' ') {
                ans = ' ' + temp + ans;
                temp = "";
            }
            temp += s[i];
            flag = false;
        }
        ans = temp + ans;
        return ans;
    }
};
