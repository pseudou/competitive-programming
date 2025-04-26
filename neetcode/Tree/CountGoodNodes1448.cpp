

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
// simple recursion. Just keep a track of previous good node.
// if curr node is good node then add 1 and return sum of left side good nodes and right side good nodes.

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
    int goodN(TreeNode* root, TreeNode* prev) {
        if (root == NULL) return 0;
        TreeNode* isgood = prev;
        if (prev == NULL ||  root->val >= prev->val) {
            isgood =root;
        }
        int l = goodN(root->left, isgood);
        int r = goodN(root->right, isgood);

        return isgood== prev? l+r : 1+l+r;
    }
    int goodNodes(TreeNode* root) {
        return goodN(root, NULL);
    }
};