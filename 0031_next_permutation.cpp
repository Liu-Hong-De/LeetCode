/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory. */

// Difficulty: Medium
// Runtime: 3 ms, faster than 81.88% of C++ online submissions for Next Permutation.
// Memory Usage: 12 MB, less than 93.55% of C++ online submissions for Next Permutation.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        int j = nums.size()-1;
        while(i > 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if(i >= 0) {
            while(j > 0 && nums[j] <= nums[i]) {
                j--;
            }
            if(i != j) {
                swap(nums[i], nums[j]);
            }
        }
        if(i == j) {
            reverse(nums.begin(), nums.end());
        }
        else {
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
