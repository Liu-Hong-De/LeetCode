// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Difficulty: Hard
// Runtime: 16 ms, faster than 99.13% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 88.8 MB, less than 99.72% of C++ online submissions for Median of Two Sorted Arraysorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size()) / 2;		// 判斷中間位置 
        bool flag = false;			//上一步驟移動的vector為何 
        int i = 0, j = 0;			// 在vector中移動的指標 
        double ans = 0;
        
//        處理其中一vector為空的情況 
        if(nums1.size() == 0) {
            if(nums2.size() % 2 == 0) {
                ans = (double)(nums2[mid-1] + nums2[mid]) / 2;
            }
            else {
                ans = nums2[mid];
            }
            return ans;
        }
        if(nums2.size() == 0) {
            if(nums1.size() % 2 == 0) {
                ans = (double)(nums1[mid-1] + nums1[mid]) / 2;
            }
            else {
                ans = nums1[mid];
            }
            return ans;
        }
        
//        在還未到達中點且兩vector都還有元素時持續遍歷 
        while(i + j < mid && i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                i++;
                flag = true;
            }
            else {
                j++;
                flag = false;
            }
        }
        
//        若有一方元素先用完且還未到達中點 ，則持續尋訪 剩餘元素直到終點 
        while(i == nums1.size() && i+j < mid) {
            j++;
            flag = false;
        }
        while(j == nums2.size() && i+j < mid) {
            i++;
            flag = true;
        }
        
//        判斷兩陣列和是奇數還是偶數 
        if((nums1.size() + nums2.size()) % 2 == 0) {
            if(flag) {
                if(i == nums1.size()) {
                    ans = (double)(nums1[i-1] + nums2[j]) / 2;
                }
                else if(j == nums2.size()) {
                    ans = (double)(nums1[i] + nums1[i-1]) / 2;
                }
                else {
                    if(nums1[i] <= nums2[j]) {
                        ans = (double)(nums1[i-1] + nums1[i]) / 2;
                    }
                    else {
                        ans = (double)(nums1[i-1] + nums2[j]) / 2;
                    }
                }
            }
            else {
                if(i == nums1.size()) {
                    ans = (double)(nums2[j] + nums2[j-1]) / 2;
                }
                else if(j == nums2.size()) {
                    ans = (double)(nums1[i] + nums2[j-1]) / 2;
                }
                else {
                    if(nums1[i] <= nums2[j]) {
                        ans = (double)(nums1[i] + nums2[j-1]) / 2;
                    }
                    else {
                        ans = (double)(nums2[j] + nums2[j-1]) / 2;
                    }
                }
            }
        }
        else {
            if(i == nums1.size()) {
                ans = nums2[j];
            }
            else if(j == nums2.size()) {
                ans = nums1[i];
            }
            else {
                if(nums1[i] <= nums2[j]) {
                    ans = nums1[i];
                }
                else {
                    ans = nums2[j];
                }
            } 
        }
        return ans;
    }
};
