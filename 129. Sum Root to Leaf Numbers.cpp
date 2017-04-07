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
    void getSum(TreeNode* node,int curSum, int& sum)
    {
        if (node) {
            curSum += node->val;
            if (!node->left && !node->right) {
                sum += curSum;
            } 
            getSum(node->left, curSum * 10, sum);
            getSum(node->right, curSum * 10, sum);
        }
    }
    
    int getSum(TreeNode* node, int sum) {
        if (!node)
            return 0;
        int s = sum * 10 + node->val;
        if (!node->left && !node->right) {
            return s;
        }
        
        return getSum(node->left, s) + getSum(node->right,s);
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return getSum(root, 0);
    }
};