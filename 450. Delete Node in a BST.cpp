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
    inline pair<TreeNode*,TreeNode*> getSuccessor(TreeNode* node) {
        auto nodeSuccessor = node->right;
        auto nodeSuccessorParent = node;
        
        while (nodeSuccessor->left) {
            nodeSuccessorParent = nodeSuccessor;
            nodeSuccessor = nodeSuccessor->left;
        }

        return make_pair(nodeSuccessorParent,nodeSuccessor);
    }
 
    inline void transPlant(TreeNode* &root, TreeNode* node, TreeNode* plantNode) {
        auto nodeP = getNodeParent(root, node);
        
        if (nodeP) {
            if (node == nodeP->left) {
                nodeP->left = plantNode;
            }  else {
                nodeP->right = plantNode; 
            }
        } else {
            root = plantNode;
        }
        
    }
  
    inline TreeNode* findKey(TreeNode* root, int key) {
        while (root) {
            if (root->val < key) {
                root = root->right;
            }
            else if (root->val > key) {
                root = root->left;
            }
            else {
               return root;  
            }
        }
        return NULL;
    }
    
    inline TreeNode* getNodeParent(TreeNode* root, TreeNode* node) {
        TreeNode* nodeP = NULL;
        
        while (root) {
            if (node->val < root->val ) {
                nodeP = root;
                root = root->left;
            }
            else if (node->val > root->val) {
                nodeP = root;
                root = root->right;
            }
            else {
                return nodeP;
            }
        }
        
         return nodeP;
    }
     void deleteNode(TreeNode* &root, TreeNode* node) {
        auto nodeIsGoingToBeDeleted = node;
 
        if (node->left == NULL) {
            transPlant(root, node, node->right);
            node = node->right;
        } else if (node->right == NULL) {
            transPlant(root, node, node->left);
            node = node->left;
        } else if (node->right->left == NULL) {
            transPlant(root, node, node->right);
            node->right->left = node->left;
        } else {
            auto p = getSuccessor(node);
            auto nodeSuccessorParent = p.first;
            auto nodeSuccessor = p.second;
          
            transPlant(root, node, nodeSuccessor);
            nodeSuccessor->left = node->left;
            nodeSuccessorParent->left = nodeSuccessor->right;
            nodeSuccessor->right = node->right;
        }
        
        delete nodeIsGoingToBeDeleted;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto node = findKey(root, key);
        if (node) {
           deleteNode(root, node);
        } 
        return root;
    }
private:
    
};