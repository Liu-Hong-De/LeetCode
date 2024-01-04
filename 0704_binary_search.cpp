/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.*/

// Difficulty: Easy
// Runtime: 32 ms, faster than 87.95% of C++ online submissions for Binary Search.
// Memory Usage: 27.5 MB, less than 63.06% of C++ online submissions for Binary Search.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
    
    int binary_search(vector<int>& nums, int low, int high, int target) {
        if(nums[low] == target) {
            return low;
        }
        else if(nums[high] == target) {
            return high;
        }
        else if(low+1 >= high) {
            return -1;
        }
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(target < nums[mid]) {
            return binary_search(nums, low, mid-1, target);
        }
        else {
            return binary_search(nums, mid+1, high, target);
        }
        return -1;
    }
};
