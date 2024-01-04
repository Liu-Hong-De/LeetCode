/*You are given a 0-indexed m x n binary matrix grid.

A 0-indexed m x n difference matrix diff is created with the following procedure:

Let the number of ones in the ith row be onesRowi.
Let the number of ones in the jth column be onesColj.
Let the number of zeros in the ith row be zerosRowi.
Let the number of zeros in the jth column be zerosColj.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
Return the difference matrix diff.*/

// Runtime: 183 ms, Beats 81.55% of users with C++
// Memory: 116.70 MB, Beats 76.99% of users with C++

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int M = grid.size();                // row size
        int N = grid[0].size();             // column size
        vector<int> onesRowi(M, 0);          // store the number of 1s in every rows
        vector<int> onesColj(N, 0);          // store the number of 1s in every column
        
        // calculate the number of 1s in the grid
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                onesRowi[i] += grid[i][j];
                onesColj[j] += grid[i][j];
            }
        }

        // generate the final grid
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                grid[i][j] = 2 * (onesRowi[i] + onesColj[j]) - M - N;
            }
        }
        return grid;
    }
};