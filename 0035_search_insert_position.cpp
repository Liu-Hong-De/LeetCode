/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. */

// Difficulty: Easy
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


// Runtime: 4 ms, faster than 80.31% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.7 MB, less than 72.17% of C++ online submissions for Search Insert Position.

// O(log n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	// insert at first position
        if(nums[0] >= target) {
            return 0;
        }
        // insert at last position
        else if(nums[nums.size()-1] < target) {
            return nums.size();
        }
        else {
            return binary_search(nums, 0, nums.size()-1, target);
        }
    }
    
    int binary_search(vector<int>& nums, int low, int high, int target) {
        if(low+1 == high) {
            return high;
        }
        int mid = (low + high) / 2;
        if(target <= nums[mid]) {
            return binary_search(nums, low, mid, target);
        }
        else {
            return binary_search(nums, mid, high, target);
        }
        return -1;
    }
};
