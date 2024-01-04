/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/

// Difficulty: Easy
// Runtime: 4 ms, faster than 97.38% of C++ online submissions for Two Sum.
// Memory Usage: 9 MB, less than 58.54% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            
            if(cache.find(need) == cache.end()) {
                cache.insert(pair(nums[i], i));
            }
            else {
                ans.push_back(cache[need]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
