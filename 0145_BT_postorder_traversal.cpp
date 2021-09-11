/* Given the root of a binary tree, return the postorder traversal of its nodes' values. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 8.3 MB, less than 85.64% of C++ online submissions for Binary Tree Postorder Traversal.


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
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
    
    void postorder(TreeNode* root) {
        if(root != NULL) {
            postorder(root->left);
            postorder(root->right);
            ans.push_back(root->val);
        }
    }
    
private:
    vector<int> ans;
};
