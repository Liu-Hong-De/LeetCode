/*You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.*/

// Difficulty: Medium
// Runtime: 108 ms, Beats 91.16% of users with C++
// Memory: 85.13 MB, Beats 63.17% of users with C++

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        // count the occurrence of each number
        for(int i: nums) {
            mp[i]++;
        }

        for(auto i: mp) {
            double count = i.second;
            if(count == 1) {
                return -1;
            }
            ans += ceil(count / 3);
        }
        return ans;
    }
};