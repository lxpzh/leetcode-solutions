/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

   void inOrderTree(TreeNode* root, string& str) {
        if (root) {
            str += std::to_string(root->val);
            str += ' ';
            inOrderTree(root->left, str);
            inOrderTree(root->right, str);
        } else {
            str += "# ";
        }
    }
    string serialize(TreeNode* root) {
        string str;
        inOrderTree(root, str);
        return str ;
    }
 
    vector<string> split(const string& str, char ch) {
 /*       vector<string> svec;
        stringstream ss;
        ss.str(str);
        
        string item;
        while (getline(ss, item, ch)) {
            svec.push_back(item);
        }
        return svec;
        */
        istringstream iss(str);
        vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
        return tokens;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* decodeStr(const vector<string>& svec, int &index) {
        if (svec[index] == "#") {
             return NULL;
        } else {
            int val = atoi(svec[index].c_str());
            TreeNode* node = new TreeNode(val);
            node->left = decodeStr(svec, ++index);
            node->right = decodeStr(svec, ++index);
            return node;
        }
    }
    
    TreeNode* deserialize(string data) {
        auto svec = split(data, ' ');
        
        int index = 0;
        return decodeStr(svec, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));