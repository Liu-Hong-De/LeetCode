/* Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length. */

// Difficulty: Easy
// Runtime: 4 ms, faster than 52.59% of C++ online submissions for Remove Element.
// Memory Usage: 8.6 MB, less than 92.99% of C++ online submissions for Remove Element.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int temp;
        int count = 0;
        int j = nums.size() - 1;
        
        if(nums.size() == 1) {
            if(nums[0] == val) {
                count++;
            }
        }
//        利用兩個指遭分別從頭尾向中間掃描，在頭找到關鍵值跟尾的非關鍵值做交換，直到尾的指標等於頭的指標為止 
        else {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != val) {
                    continue;
                }
                for(; j >= i; j--) {
                    if(nums[j] != val) {
                        temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        count++;
                        j--;
                        break;
                    }
                    else {
                        count++;
                    }
                }
            }
        }
        return nums.size() - count;
    }
};
