/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    void inorderTree(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while (!s.empty() || node) {
            while (node) {
                s.push(node);
                node = node->left;
            }
         
            node = s.top();
            s.pop();
            cout << node->val << endl;;
            node = node->right;
        }
    }
 
    BSTIterator(TreeNode *root) {
        node = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while (node) {
            s.push(node);
            node = node->left;
        }
       return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        node = s.top();
        int value = node -> val;
        s.pop();
        node = node->right;
        
        return value;
    }
    
private:
    stack<TreeNode*> s;
    TreeNode* node;
};