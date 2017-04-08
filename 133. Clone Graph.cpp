/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // this function is just for showing graph
    void showGraph(UndirectedGraphNode *root)
    {
        if (!root) 
        {
            return;
        }

        queue<UndirectedGraphNode*> q;
        q.push(root);
        unordered_set<UndirectedGraphNode*> s;
        s.insert(root);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            cout << node->label << " : ";

            for (auto gn : node->neighbors)
            {
                if (s.find(gn) == s.end())
                {
                    q.push(gn);
                    s.insert(gn);
                }
                cout << gn->label << ",";
            }
            cout << endl;
        }
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node)
        {
            return NULL;
        }

        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;

        q.push(node);
        UndirectedGraphNode* rootCopy = new UndirectedGraphNode(node->label);
        m.insert({node, rootCopy});

        while (!q.empty())
        {
            auto graphNode = q.front();
            q.pop();

            auto root = m[graphNode];

            for (auto gn : graphNode->neighbors)
            {
                auto iter = m.find(gn);
                if (iter == m.end())
                {
                    q.push(gn);
                    auto newNode = new UndirectedGraphNode(gn->label);
                    root->neighbors.push_back(newNode);
                    m.insert({gn, newNode});
                }
                else
                {
                    auto newNode = iter->second;
                    root->neighbors.push_back(newNode);
                }
            }
        }

        return rootCopy;
    }
};
