/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function. */

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.2 MB, less than 67.56% of C++ online submissions for Sort Colors.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
    }
    
    void quicksort(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return;
        }
        
        int i = left;
        int j = right;
        int pivot = nums[left];
        
        while(i != j) {
            while(nums[j] > pivot && i < j) {
                j--;
            }
            while(nums[i] <= pivot && i < j) {
                i++;
            }
            if(i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        nums[left] = nums[i];
        nums[i] = pivot;
        
        quicksort(nums, left, i-1);
        quicksort(nums, i+1, right);
    }
};
