/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. */

// Difficulty: Easy
// Runtime: 4 ms, faster than 92.21% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 18.7 MB, less than 88.11% of C++ online submissions for Maximum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        depth(root, 0);
        return ans;
    }
    
    void depth(TreeNode* root, int count) {
        if(root == NULL) {
            if(count > ans)
                ans = count;
        }
        else {
            depth(root->left, count+1);
            depth(root->right, count+1);
        }
    }

private:
    int ans = 0;
};
