// Given a string s, return the longest palindromic substring in s.

// Difficulty: Medium
// Runtime: 176 ms, faster than 42.31% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.9 MB, less than 95.26% of C++ online submissions for Longest Palindromic Substring.

class Solution {
public:
    string longestPalindrome(string s) {
        int first = 0, length = 0;			// 紀錄回文產生的位置和長度 
        bool flag = false;
        string ans = "";
        
        for(int i = 0; i < s.length(); i++) {
            for(int j = s.length()-1; j > i; j--) {
//            	頭尾相同時逐漸往內移動判斷是否是回文 
                if(s[i] == s[j]) {
                    first = i;
                    length = j-i+1;
                    
                    while(i < j) {
                        if(s[i] != s[j]) {
                            flag = false;
                            break;
                        }
                        else {
                            flag = true;
                            i++;
                            j--;
                        }
                    }
//                    非回文時還原回原本位置繼續尋找 
                    if(!flag) {
                        i = first;
                        j = first + length - 1;
                    }
                }
                
                if(flag) {
                    if(length > ans.length()) {
                        ans = s.substr(first, length);
                    }
                    i = first;
                    flag = false;
                    break;
                }
            }
        }
        
        if(ans == "") {
            ans = s[0];
        }
        
        return ans;
    }
};
