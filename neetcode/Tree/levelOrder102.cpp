
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// Ans: do a BFS.

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

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        vector<vector<int>> ans;
        if (root== NULL) return ans;
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i=0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            ans.push_back(level);
        }

        return ans;
    }
};