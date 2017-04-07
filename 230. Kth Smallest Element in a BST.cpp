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
    void kthSmallestImpl(TreeNode* root, int k, int& curIndex, int& value) {
        if (root) {
            kthSmallestImpl(root->left, k, curIndex, value);
            if (++curIndex == k) {
                value = root->val;
            }
            kthSmallestImpl(root->right, k, curIndex, value);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL || k <= 0) {
            return 0x80000000;
        }
        int curIndex = 0;
        int value;
        kthSmallestImpl(root, k , curIndex, value);
        
        return value;
    }
};