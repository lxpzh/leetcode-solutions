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
    bool isSymmetricImpl(TreeNode* root, TreeNode* mirrorRoot)
    {
        if (root == NULL && mirrorRoot == NULL) {
            return true;
        }
        else if (root == NULL || mirrorRoot == NULL) {
            return false;
        }
        else  {
            return  (root->val == mirrorRoot->val) &&
                    isSymmetricImpl(root->left, mirrorRoot->right) &&
                    isSymmetricImpl(root->right, mirrorRoot->left);
        }
         
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricImpl(root, root);
    }
};