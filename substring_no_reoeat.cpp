// Given a string s, find the length of the longest substring without repeating characters.
 
// Runtime: 8 ms, faster than 89.09% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.2 MB, less than 73.19% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;		// �ΥH�x�s�C�@�Ӧr���̫�@���X�{����m 
        int ans = 0, temp = 0, front = 0;;
        
        for(int i = 0; i < s.length(); i++) {
            int pos = umap[s[i]];

//			�P�_���r���b�e���O�_�w�X�{�L 
            if(pos != 0 && pos > front) {
                temp = i - pos + 1;
                front = pos;			// �ΥH�����W�@�����ƥX�{���r������m(�e)�A�H��ֹB��q�A�b����m�e����m���ݦA���p�� 
            }
            else {
                temp++;
            }
            
//            �P�_�ثe�r����׬O�_�j�󵪮� 
            if(temp > ans) {
                ans = temp;
            }

            umap[s[i]] = i+1;
        }
        return ans;
    }
};
