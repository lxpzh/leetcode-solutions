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
     TreeNode* flattenImp(TreeNode* root) {
        if (!root) {
            return NULL;
        } else {
            auto leftChild = flattenImp(root->left);
            auto rightChild = flattenImp(root->right);
            if (leftChild) {
                auto temp = leftChild;
                while (temp->right) {
                    temp = temp->right;
                }
                temp->right = rightChild;
            }
            root->right = leftChild;
                
            return root;
        }
   }
   
    void flatten(TreeNode* root) {
       //  root = flattenImp(root);
       if (root) {
          flatten(root->left);
          flatten(root->right);
          auto temp = root->right;
          root->right = root->left;
          root->left = NULL;
       }
    }
};