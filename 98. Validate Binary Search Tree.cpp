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
private:
    int lastTimeValue;
    bool firstTime;
public:
    Solution() :firstTime(true), lastTimeValue(INT_MIN) {   }
  /*  void isValidBST(TreeNode* node, bool& isValid) {
        if (node && isValid) {
            isValidBST(node->left, isValid);
            if (node->val <= lastTimeValue && !firstTime) {
                isValid = false;
            }
            firstTime = false;
            lastTimeValue = node->val;
            isValidBST(node->right,isValid);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        else {
            firstTime = true;
            bool isValid = true;
            lastTimeValue = INT_MIN;
            isValidBST(root, isValid); 
            return isValid;
        }
           
    }
    */
    
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        } 
        else {
            bool isLeftValid = isValidBST(root->left);
            bool valid = true;
            
            if (lastTimeValue >= root->val && !firstTime) {
                valid = false;
            }
            lastTimeValue = root->val;
            firstTime = false;
            
            bool isRightValid = isValidBST(root->right);
            return isLeftValid && valid && isRightValid;
        }
        
    }
};