/* Given the root of a binary tree, split the binary tree into two subtrees by removing one edge 
such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it. */

// Runtime: 112 ms, faster than 84.82% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// Memory Usage: 77.2 MB, less than 98.39% of C++ online submissions for Maximum Product of Splitted Binary Tree.

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
    int maxProduct(TreeNode* root) {
//    	calculate the sum of tree
        all = subtree(root);
//        calculate the maximum product of subtrees
        subtree(root);
        return ans % int(pow(10, 9) + 7);
    }
    
    int subtree(TreeNode* root) {
        if (root == NULL)
            return 0;
//        calculate the sum of subtree
        int subBT = subtree(root->left) + subtree(root->right) + root->val;
//        calculate the maximum product of subtrees
        ans = max(ans, ((all - subBT) * subBT));
        return subBT;
    }
    
private:
    long all = 0, ans = 0;
};
