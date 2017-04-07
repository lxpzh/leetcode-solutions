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
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right; 
    }
    
    string intToString(int value) {
        stringstream ss;
        ss << value;
        return ss.str().c_str();
    }
    
    void binaryTreePaths(TreeNode* node, vector<string>& svec, string str) {
         if (node) {
             if (isLeaf(node)) {
                 str += intToString(node->val);
                 svec.push_back(str);
             } 
             else {
                str += intToString(node->val);
                str += "->"; 
                
                binaryTreePaths(node->left, svec, str);
                binaryTreePaths(node->right, svec, str);
             }
         }   
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> svec;
         if (!root) {
             ;
         }
         else if (isLeaf(root)) {
             svec.push_back(intToString(root->val));
         }
         else {
            string s;
            binaryTreePaths(root, svec, s);
        }
        
        return svec;
    }
};