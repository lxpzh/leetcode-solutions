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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int currentLevelNodesCount = 1;
        
        while (!q.empty()) {
            int nextLevelNodesCount = 0;
            int currentMax = q.front()->val;
            
            for (int i=0; i < currentLevelNodesCount; i++) {
                auto node = q.front();
                if (currentMax < node->val) {
                    currentMax = node->val;
                }
                
                if (node->left) {
                    q.push(node->left);
                    ++nextLevelNodesCount;
                }
                if (node->right) {
                    q.push(node->right);
                    ++nextLevelNodesCount;
                }
                q.pop();
            }
            
            result.push_back(currentMax);
            currentLevelNodesCount = nextLevelNodesCount;
        }
        
        return result;
    }
};