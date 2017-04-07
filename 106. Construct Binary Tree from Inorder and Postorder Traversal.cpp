/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //#define Debug
 
class Solution {
public:
    using Iter = vector<int>::iterator;
    
    void display(Iter first, Iter last, string name) {
        cout << name << endl;
        copy(first, last, std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
    TreeNode* buildTreeImpl(Iter inorderFirst, Iter inorderLast,
                            Iter postFirst, Iter postLast)
    {
        if (inorderFirst == inorderLast || postFirst == postLast) {
            return NULL;
        } else if (std::distance(inorderFirst, inorderLast) == 1 ||
                    std::distance(postFirst, postLast) == 1) {
            return new TreeNode(*inorderFirst);                
        } else {
            auto data = *(postLast - 1);
            auto inorderPartitionPos = inorderBegin + inorderValIndexMap.find(data)->second;
            auto postorderPartitionPos = postLast - std::distance(inorderPartitionPos, inorderLast);
            
           #ifdef Debug
           { 
               display(inorderFirst,inorderPartitionPos, "inorder left");
               display(inorderPartitionPos + 1,inorderLast, "inorder right");
               display(postFirst,postorderPartitionPos, "postorder left ");
               display(postorderPartitionPos,postLast - 1, "postorder right");
           }
           #endif
            
            auto root = new TreeNode(data);
            root->left = buildTreeImpl(inorderFirst, inorderPartitionPos, 
                                       postFirst, postorderPartitionPos);
            root->right = buildTreeImpl(inorderPartitionPos + 1, inorderLast,
                                postorderPartitionPos, postLast - 1);
            return root;
        }
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderValIndexMap.insert({inorder[i], i});
        }
        inorderBegin = inorder.begin();
        return buildTreeImpl(inorder.begin(), inorder.end(), 
                            postorder.begin(), postorder.end());
    }
private:
    unordered_map<int, int> inorderValIndexMap;
    Iter inorderBegin;
};