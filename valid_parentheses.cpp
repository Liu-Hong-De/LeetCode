/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
	1. Open brackets must be closed by the same type of brackets.
	2. Open brackets must be closed in the correct order. */
	
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.3 MB, less than 46.58% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')') {
                if(!myStack.empty() && myStack.top() == '(') {
                    myStack.pop();
                }
                else {
                    return false;
                }
            }
            else if(s[i] == ']') {
                if(!myStack.empty() && myStack.top() == '[') {
                    myStack.pop();
                }
                else {
                    return false;
                }
            }
            else if(s[i] == '}') {
                if(!myStack.empty() && myStack.top() == '{') {
                    myStack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                myStack.push(s[i]);
            }
        }
        
        if(myStack.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
