/* You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island. */

// Difficulty: Easy
// Runtime: 127 ms, faster than 35.75% of C++ online submissions for Island Perimeter.
// Memory Usage: 96.2 MB, less than 58.06% of C++ online submissions for Island Perimeter.

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    ans += 4;
                    if(j != grid[i].size()-1 && grid[i][j+1] == 1) {
                        ans -= 2;
                    }
                    if(i != grid.size()-1 && grid[i+1][j] == 1) {
                        ans -= 2;
                    }
                }
            }
        }
        return ans;
    }
};
