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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ivec;

        if (root) {
            queue<TreeNode*> q;
        //    vector<TreeNode*> nodeVec;
        //    vector<int> levelNodeValueVec;
            
            q.push(root);
            while (!q.empty()) {
                vector<TreeNode*> nodeVec;
                vector<int> levelNodeValueVec;
            
                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    levelNodeValueVec.push_back(node->val);
                    
                    if (node->left) {
                        nodeVec.push_back(node->left);
                    }
                    if (node->right) {
                        nodeVec.push_back(node->right);
                    }
                }
                
                ivec.push_back(levelNodeValueVec);
                for (auto const& node : nodeVec) {
                    q.push(node);
                }
            }
        }
        
        return ivec;
    }
};