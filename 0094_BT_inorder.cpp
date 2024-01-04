// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 8.2 MB, less than 85.29% of C++ online submissions for Binary Tree Inorder Traversal.

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
    vector<int> inorderTraversal(TreeNode* root) {
        subtree(root);
        return ans;
    }
    
//    inorder¡Gleft->middle->right 
    void subtree(TreeNode* root) {
        if(root != NULL) {
            subtree(root->left);
            ans.push_back(root->val);
            subtree(root->right);
        }
    }

private:
    vector<int> ans;
};
