/* Given an integer array nums and an integer k, 
return true if it is possible to divide this array into k non-empty subsets whose sums are all equal. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition to K Equal Sum Subsets.
// Memory Usage: 9.3 MB, less than 35.23% of C++ online submissions for Partition to K Equal Sum Subsets.

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
//         �p��Ȫ��`�M�A�P�_�O�_�i�H����k��
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % k != 0) {
            return false;
        }
        
        int need = sum / k;     // �C�Ӥl���һ��`�M
        vector<int> sub(k, 0);
        sort(nums.begin(), nums.end());
//         �Y���X���̤j�Ȥj��һ��`�M�A��ܥ����i��o�X����
        if(need < nums[nums.size()-1]) {
            return false;
        }
        
        for(int i = 0; i < k; i++) {
            vector<int> pos;
//             �M�䨺�Ǥ����`�M�|�Oneed
            pos = subset(nums, need, nums.size()-1, pos);
            if(!flag) {
                return false;
            }
//             �R���w�g���ߪ��զX�A�קK���ƭp��
            for(int j = pos.size()-1; j >= 0; j--) {
                nums.erase(nums.begin()+pos[j]);
            }
        }
        return true;
    }
    
    vector<int> subset(vector<int>& nums, int need, int end, vector<int>& pos) {
        flag = false;
        for(int i = end; i >= 0; i--) {
//             ���j�M��i�઺��
            if(need > nums[i]) {
                pos = subset(nums, need-nums[i], i-1, pos);
                if(flag) {
                    pos.push_back(i);
                    break;
                }
            }
//             ���\���l��
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
