Runtime: 68 ms, faster than 58.00% of C++ online submissions for 4Sum.
Memory Usage: 13.2 MB, less than 42.67% of C++ online submissions for 4Sum.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//    	nums���Ȫ��ƶq�p��k 
        if(nums.size() < 4) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-4+1; i++) {
            for(int j = i+1; j < nums.size()-4+2; j++) {
//            	�ثe�һݭ��`�M 
                int need = target - nums[i] - nums[j];
                int left = j + 1, right = nums.size() - 1;
                
                while(left < right) {
                    if(need == nums[left] + nums[right]) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        
//                        �ۦP���ȶ����L 
                        while(left < right && nums[left] == temp[2]) {
                            left++;
                        }
                        while(left < right && nums[right] == temp[3]) {
                            right--;
                        }
                        temp.clear();
                    }
//                    �ثe�ȸ��ݨD�p 
                    else if(need > nums[left] + nums[right]) {
                        left++;
                    }
//                    �ثe�ȸ��ݨD�j 
                    else {
                        right--;
                    }
                }
                while(j < nums.size()-4+2 && nums[j+1] == nums[j]) {
                    j++;
                }
            }
            while(i < nums.size()-4+1 && nums[i+1] == nums[i]) {
                i++;
            }
            
        }
        return ans;
    }
    
private:
    // int k =4;
    vector<vector<int>> ans;
    vector<int> temp;
};
