/* Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory. */

// Runtime: 4 ms, faster than 99.06% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 13.6 MB, less than 91.64% of C++ online submissions for Remove Duplicates from Sorted Array.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
//        	把不重複的數字放到陣列前面幾項 
            if(i == 0 || nums[i-1] != nums[i]) {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};
