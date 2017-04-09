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
    int maxPathSumImpl(TreeNode* root, int& value) {
        if (root) {
            int leftVal = max(0, maxPathSumImpl(root->left, value));
            int rightVal = max(0, maxPathSumImpl(root->right, value));
        
            value = max(root->val + leftVal + rightVal, value);
          
            return max(leftVal, rightVal) + root->val;
        }  else {
            return 0;
        }  
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int value = root->val;
        int maxVal = maxPathSumImpl(root, value);

        if (maxVal < value) {
            maxVal = value;
        }
        return maxVal;
    }
 
};
