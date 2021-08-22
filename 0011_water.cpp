/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical 
lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together 
with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container. */

// Runtime: 80 ms, faster than 37.82% of C++ online submissions for Container With Most Water.
// Memory Usage: 58.9 MB, less than 35.52% of C++ online submissions for Container With Most Water.
// 待修改 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        
        while(i < j) {
            ans = max(ans, (j-i)*min(height[i], height[j]));
//            逐漸往內找可能更大的值 
            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};
