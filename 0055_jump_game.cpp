/* You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise. */

// Difficulty: Medium
// Runtime: 56 ms, faster than 82.88% of C++ online submissions for Jump Game.
// Memory Usage: 48.3 MB, less than 49.19% of C++ online submissions for Jump Game.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        int step = nums[0];
        while(pos < nums.size()-1 && step != 0) {
            pos++;
            step = step-1 >nums[pos] ? step-1 : nums[pos];
        }
        if(pos == nums.size()-1) {
            return true;
        }
        else {
            return false;
        }
    }
};
