// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.3 MB, less than 91.68% of C++ online submissions for Symmetric Tree.

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
    bool isSymmetric(TreeNode* root) {
        symmetric(root->left, root->right);
        return ans;
    }
    
    void symmetric(TreeNode* left, TreeNode* right) {
        if(left && right) {
//        	left = right
            if(left->val == right->val) {
                symmetric(left->left, right->right);
                symmetric(left->right, right->left);
            }
            else {
                ans = false;
            }
        }
//        not xor
        if((left != NULL) == (right == NULL))
            ans = false;
    }
    
private:
    bool ans = true;
};
