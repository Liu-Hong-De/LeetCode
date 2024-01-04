// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
// Memory Usage: 6.2 MB, less than 92.09% of C++ online submissions for Pascal's Triangle II.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        while(rowIndex > 0) {
            temp = ans;
            ans.clear();
            ans.push_back(1);
            if(temp.size() >= 2) {
                for(int i = 0; i < temp.size()-1; i++) {
                    ans.push_back(temp[i] + temp[i+1]);
                }
            }
            ans.push_back(1);
            rowIndex--;
        }
        return ans;
    }
    
private:
    vector<int> temp{1};
    vector<int> ans{1};
};
