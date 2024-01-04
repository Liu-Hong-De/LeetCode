/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters. */

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.6 MB, less than 62.94% of C++ online submissions for Letter Combinations of a Phone Number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return ans;
        recursive(digits, 0, "");
        return ans;
    }
    
    void recursive(string digits, int pos, string str) {
        for(int i = 0; i < mapping(digits[pos]).length(); i++) {
            if(digits.length() > pos+1) {
                recursive(digits, pos+1, str + mapping(digits[pos])[i]);
            }
            else
                ans.push_back(str + mapping(digits[pos])[i]);
        }
    }
    
    string mapping(char ch) {
        switch(ch) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
        }
        return 0;
    }
    
private:
    vector<string> ans;
};
