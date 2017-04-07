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
    void inOrderTree(TreeNode* node) {
        if (node) {
            inOrderTree(node->left);
            nodeVec.push_back(node);
            inOrderTree(node->right);
        }
    }
    
    void recoverTree(TreeNode* root) {
        inOrderTree(root);
        
        int preIndex = 0, nextIndex = 0;
        bool preIndexVisited = false;
        
        for (size_t i = 0, j = 1; j < nodeVec.size(); i++, j++) {
            if (nodeVec[i]->val > nodeVec[j]->val) {
                if (!preIndexVisited) {
                    preIndex = i;
                    nextIndex = j;
                    preIndexVisited = true;
                }  else {
                    nextIndex = j;
                }
            }
        }
        
        swap(nodeVec[preIndex]->val , nodeVec[nextIndex]->val);
    }
private:
    vector<TreeNode*> nodeVec;
};