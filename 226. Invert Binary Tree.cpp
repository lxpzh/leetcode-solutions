/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void invertTreeImpl(TreeNode* node) {
        if (node) {
            TreeNode *left = node->left, *right = node->right;
            node->left = right; node->right = left;
            if (left!=NULL) invertTreeImpl(left);
            if (right!=NULL) invertTreeImpl(right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeImpl(root);
        return root;
    }
};