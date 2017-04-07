class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root) {
            return max(maxDepth(root->left),
                       maxDepth(root->right)) + 1;
        } else {
            return 0;
        }
    }
};