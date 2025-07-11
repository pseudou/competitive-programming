

// https://leetcode.com/problems/invert-binary-tree/description/
// recursion. exhange left with right.

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->right = invertTree(left);
        root->left = invertTree(right);

        return root;
    }
};