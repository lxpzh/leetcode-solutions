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
            int leftVal = maxPathSumImpl(root->left, value);
            int rightVal = maxPathSumImpl(root->right, value);
            
            int maxVal = max(max(root->val, root->val + leftVal), root->val + rightVal);
            int tempMax = max(max(root->val + rightVal + leftVal, rightVal), leftVal);
            
            if (maxVal < tempMax && value < tempMax) {
                value = tempMax;
            }
            
            return maxVal;
        } else {
            return -1234567;
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