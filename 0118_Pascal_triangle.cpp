// Given an integer numRows, return the first numRows of Pascal's triangle.

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 6.5 MB, less than 33.88% of C++ online submissions for Pascal's Triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        for(int i = 0; i < numRows; i++) {
            if(i == 0) {
                temp.push_back(1);
            }
            else if(i == 1) {
                temp.push_back(1);
                temp.push_back(1);
            }
            else {
                temp.push_back(1);
                for(int j = 0; j < ans[i-1].size()-1; j++) {
                    temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
                }
                temp.push_back(1);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
    
private:
    vector<int> temp;
    vector<vector<int>> ans;
};
