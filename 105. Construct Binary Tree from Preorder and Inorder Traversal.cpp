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
    using Iterator = vector<int>::iterator;
    
    void displayVec(Iterator first, Iterator last) {
        copy(first, last, std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }
 
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        for (int i=0; i < inorder.size(); i++) {
            inorderValIndexMap.insert({inorder[i], i});
        }
        inorderBegin = inorder.begin();
        return buildTreeImpl(preorder.begin(), preorder.end(),
                            inorder.begin(), inorder.end());
    }
    
    TreeNode* buildTreeImpl(Iterator preorderFirst, Iterator preorderLast,
                        Iterator inorderFirst, Iterator inorderLast) {
       if (preorderFirst == preorderLast || inorderFirst == inorderLast) {
            return NULL;
        } else {
            auto data = *preorderFirst;
            auto inorderPos = inorderBegin + inorderValIndexMap.find(data)->second;
            auto root = new TreeNode(data);
            auto preorderPos = std::distance(inorderFirst, inorderPos) + preorderFirst + 1;
            
            root->left = buildTreeImpl(preorderFirst+1, preorderPos,inorderFirst, inorderPos);
            root->right = buildTreeImpl(preorderPos,preorderLast, inorderPos + 1, inorderLast);
            
            return root;
        }    
    }
private:
  std::unordered_map<int, int> inorderValIndexMap;
  Iterator inorderBegin;
};