/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (!root)
		{
			return;
		}
		queue<TreeLinkNode*> q;
		q.push(root);

		int depth = 1;
		while (!q.empty())
		{
			auto preNode = q.front();
		 
			for (auto i = 0; i < depth; i++)
			{
				auto node = q.front();
				q.pop();

				if (preNode != node)
				{
					preNode->next = node;
				}
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}

				preNode = node;
			}

			preNode->next = NULL;
			depth = (depth << 1);
		}
	}
 
};