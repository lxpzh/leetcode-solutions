// node.degree 为以node为顶点的子树有多少个节点（包括node本身），node.degree=node.left.degree + node.right.degree + 1 
//通过node.degree我们可以方便地求出该节点在中序遍历中的位置,其位置等于node.left.degree + 1
class MedianFinder {
private:
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        int degree;                 
        double val;
        TreeNode(double value) : left(nullptr), right(nullptr),parent(nullptr),
                degree(1),val(value)  {   }
    };
public:
    MedianFinder() : root(nullptr) , nodeCount(0) { }

    void insert(TreeNode* node, int num) {
        TreeNode* parent = nullptr;

        while (node) {
            parent = node;
            node->degree++;

            if (num < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        nodeCount++;
        node = new TreeNode(static_cast<double>(num));
        node->parent = parent;
        
        if (!parent) {
           root = node;
        } else if (num < parent->val){
            parent->left = node;
        } else {
            parent->right = node;
        }
    }

    void addNum(int num)
    {
        insert(root, num);
    }

    TreeNode* successor(TreeNode* node) {
        if (node->right) {
            TreeNode*  x = node->right;
            while (x->left)
                x = x->left;
            return x;
        } else {
            auto parent = node->parent;
            while (node == node->parent->right) {
                node = node->parent;
            }
            return node->parent;
        }
    }
    
    // Returns the median of current data stream
    TreeNode* findNthNode(TreeNode* node, int n) {
        while (node) {
            int nodeIndex = (node->left == nullptr) ?
                                1 : node->left->degree + 1;

            if (n < nodeIndex) {
                node = node->left;
            } else if (n > nodeIndex) {
                n -= nodeIndex;
                node = node->right;
            } else {
                break;
            }
        }
        return node;
    }

    double findMedian()
    {
        int median = 0;
        if ((nodeCount & 1) == 1) {             // Odd
            median = (nodeCount + 1) / 2;
            auto node = findNthNode(root, median);
        //    assert(node != nullptr);

            return node->val;
        }
        else {
            median = nodeCount / 2;
            auto node1 = findNthNode(root, median);
            auto node2 = successor(node1);
            return (node1->val + node2->val) / 2;
        }
    }

private:
    TreeNode *root;
    int nodeCount;
};