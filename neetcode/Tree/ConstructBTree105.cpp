
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// in preorder, first element is always root. So find this root element in inorder list. Then split the
// list into two part, left Bt and right Bt. recursively call the function for left Bt with incremented root index

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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& root) {
        if (start > end) return NULL;
        int i = start;
        for ( ; i<end; i++) {
            if (inorder[i] == preorder[root]) break;
        }
        root++;
        TreeNode* rootNode = new TreeNode(inorder[i]);

        rootNode->left = solve(preorder, inorder, start , i - 1, root);
        rootNode->right = solve(preorder, inorder, i + 1, end, root);

        return rootNode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        return solve(preorder, inorder, 0, preorder.size() -1, start);
    }
};