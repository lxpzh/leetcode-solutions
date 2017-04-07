/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        
        if (root) 
        {
            stack<TreeNode*> s;
   
            auto node = root;
            while (node || !s.empty())
            {
                while (node) 
                {
                    s.push(node);
                    result.push_back(node->val);
                    node = node->left;
                }
                
                node = s.top();
                node = node->right;
                s.pop();
            }
        }
        
        return result;
    }
};