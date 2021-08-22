// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Runtime: 16 ms, faster than 99.13% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 88.8 MB, less than 99.72% of C++ online submissions for Median of Two Sorted Arraysorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size()) / 2;		// �P�_������m 
        bool flag = false;			//�W�@�B�J���ʪ�vector���� 
        int i = 0, j = 0;			// �bvector�����ʪ����� 
        double ans = 0;
        
//        �B�z�䤤�@vector���Ū����p 
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
        
//        �b�٥���F���I�B��vector���٦������ɫ���M�� 
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
        
//        �Y���@�褸�����Χ��B�٥���F���I �A�h����M�X �Ѿl����������I 
        while(i == nums1.size() && i+j < mid) {
            j++;
            flag = false;
        }
        while(j == nums2.size() && i+j < mid) {
            i++;
            flag = true;
        }
        
//        �P�_��}�C�M�O�_���٬O���� 
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
