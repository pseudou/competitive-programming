// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Kth smallest element. Do a in order travesal, left->root->right. decrement k as you in traverse.

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
    int ans, k;
    void travs(TreeNode* root) {
        if (root == NULL || k == 0) return;
        //cout << "debug1:"<< root->val << " " << k << endl;
        travs(root->left);
        k--;
        //cout << "debug2:"<< root->val << " " << k << endl;
        if (k == 0) {ans = root->val; return;}
        travs(root->right);
    }
    int kthSmallest(TreeNode* root, int kk) {
        ans = -1;
        k = kk;
        travs(root);
        return ans;
    }
};