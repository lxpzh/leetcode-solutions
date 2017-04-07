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
	void lowestCommonAncestor(TreeNode* node,
							  TreeNode* nodeParent,
							  TreeNode* &p,
							  TreeNode* &q)
	{
	    if (node)
		{
			lowestCommonAncestor(node->left, node, p, q);
			lowestCommonAncestor(node->right, node, p, q);
 
			if (p != q)
			{
				if (p->left != q && p->right != q)
				{
					if (node == p)
					{
						p = nodeParent;
					}
				}
				else 
				{
					q = p;
				}

				if (q->left != p &&  q->right != p)
				{
					if (node == q)
					{
						q = nodeParent;
					}
				}
				else  
				{
					p = q;
				}
			}
		}

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		lowestCommonAncestor(root, NULL, p, q);
		return p;
	}
};