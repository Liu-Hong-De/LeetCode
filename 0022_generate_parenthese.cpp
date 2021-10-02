// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
// Memory Usage: 13.9 MB, less than 39.07% of C++ online submissions for Generate Parentheses.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        parenthese(n, n, "");
        return ans;
    }
    
    
    void parenthese(int left, int right, string temp) {
        if(left == 0 && right == 0) {
            ans.push_back(temp);
        }
        if(left != 0) {
            parenthese(left-1, right, temp+"(");
        }
        if(left < right) {
            parenthese(left, right-1, temp+")");
        }
    }
private:
    vector<string> ans;
};
