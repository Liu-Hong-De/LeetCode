/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. */

// Runtime: 4 ms, faster than 90.05% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.6 MB, less than 92.04% of C++ online submissions for Search Insert Position.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(target <= nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
};
