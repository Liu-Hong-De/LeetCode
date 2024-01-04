/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum. */

// Difficulty: Medium
// Runtime: 8 ms, faster than 73.28% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13 MB, less than 91.85% of C++ online submissions for Maximum Subarray.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i] + nums[i-1]);
            if(ans <= nums[i]) {
                ans = nums[i];
            }
        }
        return ans;
    }
};
