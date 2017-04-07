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
    int getHeight(TreeNode *node, bool& isBalance) {
        if (!node) {
            return 0;
        } else {
            int leftHeight = getHeight(node->left, isBalance);
            int rightHeight = getHeight(node->right, isBalance);
            if (abs(leftHeight - rightHeight) > 1) {
                isBalance = false;
            }
            return (leftHeight > rightHeight ? leftHeight+1 : rightHeight + 1);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        bool isBalance = true;
        getHeight(root, isBalance);
        
        return isBalance;
    }
};