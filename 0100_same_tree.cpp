/* Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
// Memory Usage: 10 MB, less than 76.89% of C++ online submissions for Same Tree.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p != NULL) && (q != NULL)) {
            if(p->val == q->val) {
                isSameTree(p->left, q->left);
                isSameTree(p->right, q->right);
            }
            else
                ans = false;
        }
//        not xor
        else if((p != NULL) == (q == NULL))
            ans = false;
        return ans;
    }
    
private:
    bool ans = true;
};
