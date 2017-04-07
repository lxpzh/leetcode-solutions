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
    vector<vector<int>> levelOrderBottom(TreeNode* root) { 
        vector<vector<int>> result;
        if (root) {
            vector<int> levelNodeValue;
            queue<TreeNode*> q;
            int levelNodesCount = 1;
            
            q.push(root);
            while (!q.empty()) {
                int count = 0;

                for (int i = 0; i < levelNodesCount; i++) {
                    auto node = q.front();
                    levelNodeValue.push_back(node->val);
                    q.pop();
                    
                    if (node->left) {
                        q.push(node->left);
                        ++count;
                    }
                    if (node->right) {
                        q.push(node->right);
                        ++count;
                    }
                }
                
                levelNodesCount = count;
                result.push_back(levelNodeValue);
                levelNodeValue.clear();
            }
            
            reverse(result.begin(), result.end());
        }
        
        return result;
    }
};