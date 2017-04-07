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
    /*
    int pathSumImpl(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        int n = (root->val == sum);
        return    pathSumImpl(root->left, sum - root->val) + n +
                   pathSumImpl(root->right, sum - root->val);
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return pathSumImpl(root, sum) + pathSum(root->left, sum) + 
                                        pathSum(root->right, sum);
    }
    */
    
    int pathSumImpl(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
         
        int n = (root->val == sum) ? 1 : 0;
 
        auto result = n + pathSumImpl(root->left, sum - root->val) + 
                 pathSumImpl(root->right, sum - root->val);
                 
        return result;
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        
        return pathSumImpl(root, sum) + pathSum(root->left, sum) + 
                                        pathSum(root->right, sum);
    }
 
};