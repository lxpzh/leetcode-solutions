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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if (root) {
            queue<TreeNode*> q;
            int levelNodesCount = 1;
            
            q.push(root);
            while (!q.empty()) {
                int count = 0;
                bool firstTime = true;
                
                for (int i = 0; i < levelNodesCount; i++) {
                    auto node = q.front();
                    if (firstTime) {
                        result.push_back(node->val);
                        firstTime = false;
                    }
                    q.pop();
                    
                    if (node->right) {
                        q.push(node->right);
                        ++count;
                    }
                    if (node->left) {
                        q.push(node->left);
                        ++count;
                    }
                }
                
                levelNodesCount = count;
            }
        }
        return result;
    }
};