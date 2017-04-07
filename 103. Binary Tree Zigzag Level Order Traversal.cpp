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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ivec;

        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            int level = 0;
            
            while (!q.empty()) {
                vector<TreeNode*> nodeVec;
                vector<int> levelNodeValueVec;
                ++level;
                
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
                
                for (auto const& node : nodeVec) {
                    q.push(node);
                }
                
                if ((level & 1) == 0) {
                    reverse(levelNodeValueVec.begin(), levelNodeValueVec.end()) ;
                }
                ivec.push_back(levelNodeValueVec);
            }
        }
        
        return ivec;
    }
};