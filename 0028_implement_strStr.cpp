/* Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement strStr().
// Memory Usage: 6.7 MB, less than 80.69% of C++ online submissions for Implement strStr().

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
