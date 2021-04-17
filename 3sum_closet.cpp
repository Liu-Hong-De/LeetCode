/* Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest 
to target. Return the sum of the three integers. You may assume that each input would have exactly one solution. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.9 MB, less than 6.57% of C++ online submissions for 3Sum Closest.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int gap = INT_MAX;		// the distance between the target and the nums
        int ans = 0;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < gap) {
                    gap = abs(sum - target);
                    ans = sum;
                }
                if(sum < target) {
                    j++;
                }
                else if(sum > target) {
                    k--;
                }
                else {
                    return target;
                }
            }
        }
        return ans;
    }
};
