// Given a string s, find the length of the longest substring without repeating characters.
 
// Runtime: 8 ms, faster than 89.09% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.2 MB, less than 73.19% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;		// 用以儲存每一個字元最後一次出現的位置 
        int ans = 0, temp = 0, front = 0;;
        
        for(int i = 0; i < s.length(); i++) {
            int pos = umap[s[i]];

//			判斷此字元在前面是否已出現過 
            if(pos != 0 && pos > front) {
                temp = i - pos + 1;
                front = pos;			// 用以紀錄上一次重複出現的字元的位置(前)，以減少運算量，在此位置前的位置不需再做計算 
            }
            else {
                temp++;
            }
            
//            判斷目前字串長度是否大於答案 
            if(temp > ans) {
                ans = temp;
            }

            umap[s[i]] = i+1;
        }
        return ans;
    }
};
