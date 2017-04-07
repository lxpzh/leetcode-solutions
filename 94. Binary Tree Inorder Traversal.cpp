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
    vector<int> inorderTree(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> ivec;
        TreeNode* node = root;
        
        while (!s.empty() || node) {
            while (node) {
                s.push(node);
                node = node->left;
            }
         
            node = s.top();
            s.pop();
            ivec.push_back(node->val);
            node = node->right;
        }
        
        return ivec;
    }
    
    void inorderRecur(TreeNode *root, vector<int>& ivec) {
        if (root) {
            inorderRecur(root->left, ivec);
            ivec.push_back(root->val);
            inorderRecur(root->right, ivec);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // return inorderTree(root);
        vector<int> ivec;
        inorderRecur(root, ivec);
        return ivec;
    }
};