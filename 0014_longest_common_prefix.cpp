/* Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".  */

// Difficulty: Easy
// Runtime: 4 ms, faster than 84.19% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.2 MB, less than 81.02% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            for(int j = 0; j < ans.length(); j++) {
                if(ans[j] != strs[i][j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
        return ans;
    }
};
