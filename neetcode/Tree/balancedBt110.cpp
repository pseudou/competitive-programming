
// https://leetcode.com/problems/balanced-binary-tree/description/
// first set global variable as true.
// recursively calculate left height, and right height with return val as height. if lh -rh > 1 then set global variable as
// false. return global variable.

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
    int height(TreeNode* root, bool& log) {
        if (root == NULL) return 0;
        int lh = height(root->left, log);
        int rh = height(root->right, log);
        if (abs(lh-rh) > 1) log = false;
        return 1 + max(lh, rh);

    }
    bool isBalanced(TreeNode* root) {
        bool log = true;
        height(root, log);
        return log;
    }
};