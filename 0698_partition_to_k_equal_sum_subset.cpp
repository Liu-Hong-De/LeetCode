/* Given an integer array nums and an integer k, 
return true if it is possible to divide this array into k non-empty subsets whose sums are all equal. */

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition to K Equal Sum Subsets.
// Memory Usage: 9.3 MB, less than 35.23% of C++ online submissions for Partition to K Equal Sum Subsets.

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
//         計算值的總和，判斷是否可以分成k份
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % k != 0) {
            return false;
        }
        
        int need = sum / k;     // 每個子集所需總和
        vector<int> sub(k, 0);
        sort(nums.begin(), nums.end());
//         若集合中最大值大於所需總和，表示必不可能得出答案
        if(need < nums[nums.size()-1]) {
            return false;
        }
        
        for(int i = 0; i < k; i++) {
            vector<int> pos;
//             尋找那些元素總和會是need
            pos = subset(nums, need, nums.size()-1, pos);
            if(!flag) {
                return false;
            }
//             刪掉已經成立的組合，避免重複計算
            for(int j = pos.size()-1; j >= 0; j--) {
                nums.erase(nums.begin()+pos[j]);
            }
        }
        return true;
    }
    
    vector<int> subset(vector<int>& nums, int need, int end, vector<int>& pos) {
        flag = false;
        for(int i = end; i >= 0; i--) {
//             遞迴尋找可能的解
            if(need > nums[i]) {
                pos = subset(nums, need-nums[i], i-1, pos);
                if(flag) {
                    pos.push_back(i);
                    break;
                }
            }
//             成功找到子集
            else if(need == nums[i]) {
                pos.push_back(i);
                flag = true;
                return pos;
            }
        }
        return pos;
    }
    
private:
    int sum = 0;
    bool flag = false;
};
