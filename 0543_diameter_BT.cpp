/* Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them. */

// Runtime: 8 ms, faster than 81.33% of C++ online submissions for Diameter of Binary Tree.
// Memory Usage: 20.2 MB, less than 64.86% of C++ online submissions for Diameter of Binary Tree.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int count = 0;
        tall(root, count);
        return count;
    }
    
    int tall(TreeNode* root, int &count) {
        if(!root) {
            return 0;
        }
        int left = tall(root->left, count);
        int right = tall(root->right, count);
        count = max(count, left + right);
        return max(left, right)+1;
    }
};
