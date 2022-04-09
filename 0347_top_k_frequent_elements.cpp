// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Runtime: 16 ms, faster than 82.46% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 13.6 MB, less than 89.57% of C++ online submissions for Top K Frequent Elements.

class Solution {
public:
    int partition(vector<pair<int, int>>& cur, int l, int r) {
        int pivot = cur[l].second;
        int value = cur[l].first;
        while(l < r) {
            while(l < r && cur[r].second <= pivot)
                r--;
            cur[l] = cur[r];
            while(l < r && cur[l].second >= pivot)
                l++;
            cur[r] = cur[l];
        }
        cur[l].first = value;
        cur[l].second = pivot;
        return l;
    }
    
    void quick_sort(vector<pair<int, int>>& cur, int l, int r, int k) {
        if(l >= r)
            return;
        int pivot = partition(cur, l, r);
        if(pivot == k)
            return;
        if(pivot < k)
            quick_sort(cur, pivot+1, r, k);
        else
            quick_sort(cur, l, pivot-1, k);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        vector<pair<int, int>> cur;
        vector<int> ans(k);
        
        for(int i : nums) {
            umap[i]++;
        }
        for(auto i : umap) {
            cur.emplace_back(i);
        }
        quick_sort(cur, 0, cur.size()-1, k-1);
        for(int i = 0; i < k; i++) {
            ans[i] = cur[i].first;
        }
        return ans;
    }
};
