/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. */

// Runtime: 64 ms, faster than 81.44% of C++ online submissions for 3Sum.
// Memory Usage: 22.8 MB, less than 37.40% of C++ online submissions for 3Sum.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        if(nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        
//        固定一數，找另外兩數和為固定數*-1的組合 
        for(int i = 0; i < nums.size()-2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            if(nums[i] > 0) {		// 當固定數為正數時，另外兩數必比固定數大 
                break;
            }
            else if(i > 0 && nums[i] == nums[i-1]) {		// 重複數字跳過以免重複處理 
                continue;
            }
            
            while(j < k) {
                int sum = nums[j] + nums[k];
//                向內逐漸尋找可能組合 
                if(sum < -1 * nums[i]) {
                    j++;
                }
                else if(sum > -1 * nums[i]) {
                    k--;
                }
                else {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    temp.clear();
                    j++;
                    k--;
                }
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());		// 去除重複 
        return ans;
    }
};
