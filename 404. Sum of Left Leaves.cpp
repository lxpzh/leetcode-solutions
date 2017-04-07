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
    void sumOfLeftLeavesImp(TreeNode* node, TreeNode* nodeParent, int& sum) {
        if (node) {
            sumOfLeftLeavesImp(node->left, node, sum);
            if (nodeParent && node == nodeParent->left && node->left == NULL && node->right == NULL) {
                sum += node->val;
            }
            sumOfLeftLeavesImp(node->right, node, sum);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (root->left == NULL && root->right == NULL)) {
            return 0;
        } else {
            int sum = 0;
            sumOfLeftLeavesImp(root, NULL, sum);
            
            return sum;
        }
    }
};