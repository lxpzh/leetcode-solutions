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
    void traverse(TreeNode* root, int sum, vector<int>& temp) {
        if (root) {
            temp.push_back(root->val);
            // if root is leaf
            if (!root->left && !root->right) {
                if (sum == root->val) {
                    result.push_back(temp);
                } 
            } else {
                traverse(root->left, sum - root->val, temp);
                if (root->left) {
                    temp.pop_back();
                }
                traverse(root->right, sum - root->val, temp);
                if (root->right) {
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        result.reserve(10);
        temp.reserve(300);
        traverse(root, sum, temp);
        return result;
    }
    
private:
    vector<vector<int>> result;
};