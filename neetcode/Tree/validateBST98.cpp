
// https://leetcode.com/problems/validate-binary-search-tree/

// keep a lm and rm. check if the root is between lm and rm and recursion

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
    bool isV(TreeNode* root, long lm, long rm) {
        if (root == NULL) return true;
        bool ans = false;
        if ((lm < root->val && root->val < rm)) ans = true;
        return ans && isV(root->left, lm, root->val) && isV(root->right, root->val, rm);
    }

    bool isValidBST(TreeNode* root) {
        return isV(root, LONG_MIN,LONG_MAX);
    }
};