class Solution {
public:
    struct Node {
        unordered_set<int> neighbors;
        bool isLeaf() 
        {
            return neighbors.size() == 1;
        }
    };
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) 
        {
            return vector<int>{0};
        }
        if (n == 1) 
        {
            return vector<int>{0, 1};
        }
        
        vector<Node> graph(n);
        
        for (auto const& p : edges)
        {
            graph[p.first].neighbors.insert(p.second);
            graph[p.second].neighbors.insert(p.first);
        }
        
        vector<int> buffer1, buffer2;
        for (int i=0; i < n; i++) 
        {
            if (graph[i].isLeaf()) 
            {
                buffer1.push_back(i);
            }
        }
        
        while (1) 
        {
            for (int i : buffer1) 
            {
                for (auto n : graph[i].neighbors) 
                {
                    graph[n].neighbors.erase(i);
                    if (graph[n].isLeaf()) 
                    {
                        buffer2.push_back(n);
                    }
                }
            }
                
           if (buffer2.empty())
           {
              return buffer1;
           }

           buffer1.clear();
           buffer1.swap(buffer2);
        }
    }
    
    void showBuffer(vector<int> const& ivec, const string& title = "")
    {
        cout << title << endl;
        for (auto i : ivec) {
            cout << i << " ";
        }
        cout << endl;
    }
};