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
  /*  int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
    */
    int getLevel(TreeNode* root) {
        int level = 0;
        
        while (root) {
            ++level;
            root = root->left;
        }
        
        return level - 1;
    }
    
    int getNodesCount(int level) {
        int sum = 1;
        
        while (--level >  0) {
            sum += ( 1 << level);
        }
        
        return sum;
    }
    
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        else {
           int level = getLevel(root); 
           int tempLevel = level;
           int nodesCount = getNodesCount(level);
      
           while (level >  0) {
              --tempLevel;
              --level;
              
              if (getLevel(root->left) == getLevel(root->right)) {
                  root = root->right;
                  nodesCount += (1 << tempLevel );
              } else {
                  root = root->left;
              } 
              
              if (tempLevel == 0) {
                 nodesCount += 1;
              }
           }
           
           return nodesCount;
        }
    }
private:
 
};