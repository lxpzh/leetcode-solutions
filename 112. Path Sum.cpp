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
    void preOrderTraverse(TreeNode* node,int curSums,int sum, bool& has_path_sum) {
        if (node) {
            curSums += node->val;
            if (!node->left && !node->right && curSums == sum) {
                has_path_sum = true;
            }
            preOrderTraverse(node->left, curSums, sum, has_path_sum);
            preOrderTraverse(node->right, curSums, sum, has_path_sum);
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool has_path_sum = false;
        preOrderTraverse(root, 0, sum, has_path_sum);
        
        return has_path_sum;
    }
};