class Solution {
public:
    //虽然做出来了，但是时间复杂度挺高
     vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ivec;
        if (!root)
            return ivec;
            
        stack<TreeNode*> s;    
        unordered_map<TreeNode*, bool> hasPrinted;
        hasPrinted[NULL] = true;
        TreeNode *node = root;
        bool firstEntered = true;

        while (!s.empty() || firstEntered) {
            while (node && hasPrinted.find(node) == hasPrinted.end()) {  // node has not printed
                s.push(node);
                node = node->left;
            }
            firstEntered= false;
            node = s.top();

            if ((hasPrinted.find(node->left) != hasPrinted.end() &&
                 hasPrinted.find(node->right) != hasPrinted.end())) {
                    ivec.push_back(node->val);
                    hasPrinted[node] = true;
                    s.pop();
            } else {
                auto nodeParent = node;
                node = node->right;
                
                if (node == NULL) {
            //        cout << nodeParent->val << endl;
                    ivec.push_back(nodeParent->val);
                    hasPrinted[nodeParent] = true;
                    s.pop();
                }
            }
        }

        return ivec;
    }
};
