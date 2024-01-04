// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 8.5 MB, less than 45.94% of C++ online submissions for Binary Tree Preorder Traversal.

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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
    
    void preorder(TreeNode* root) {
        if(root != NULL) {
            ans.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
    
private:
    vector<int> ans;
};
