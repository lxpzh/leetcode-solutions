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
    int findBottomLeftValue(TreeNode* root) {
        assert(root != NULL);
        
        queue<TreeNode*> q;
        q.push(root);
        int curLevelNodeCount = 1;
        int result = -1;
        
        while (!q.empty()) {
            int nexLevelNodeCount = 0;
            bool firstEntered = true;
 
            for (int i = 0 ; i < curLevelNodeCount; i++) {
                auto node = q.front();
                q.pop();
 
                if (firstEntered) {
                   if (!node->left && !node->right) {
                       result = node->val;
                       firstEntered = false;
                   } 
                }    
                
                if (node->left) {
                    q.push(node->left);
                    nexLevelNodeCount++;
                }
                if (node->right) {
                    q.push(node->right);
                    nexLevelNodeCount++;
                }
            }
                
            curLevelNodeCount = nexLevelNodeCount;
        }
        
        return result;
    }
};
