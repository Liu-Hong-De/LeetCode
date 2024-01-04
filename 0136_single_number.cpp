/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space. */

// Difficulty: Easy
// Runtime: 24 ms, faster than 40.63% of C++ online submissions for Single Number.
// Memory Usage: 16.8 MB, less than 99.23% of C++ online submissions for Single Number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i+=2) {
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return 0;
    }
};
