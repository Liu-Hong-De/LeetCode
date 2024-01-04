/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than floor(n / 2) times. 
You may assume that the majority element always exists in the array. */

// Difficulty: Easy
// Runtime: 12 ms, faster than 96.48% of C++ online submissions for Majority Element.
// Memory Usage: 19.6 MB, less than 51.88% of C++ online submissions for Majority Element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
//    	²Î­p¥X²{¦¸¼Æ 
        for(int i = 0; i < nums.size(); i++) {
            if(num.find(nums[i]) == num.end()) {
                num[nums[i]] = 1;
            }
            else {
                num[nums[i]] += 1;
            }
        }
        
//        §ämax 
        for(auto i = num.begin(); i != num.end(); i++) {
            if(i->second > count) {
                count = i->second;
                ans = i->first;
            }
        }
        return ans;
    }
    
private:
    unordered_map<int, int> num;
    int count = 0;
    int ans;
};
