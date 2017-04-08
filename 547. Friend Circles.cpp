class Solution {
public:
    void init()
    {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
    
    int find(int x)
    {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void merge(int x, int y)
    {
        if (x == y) {
            return ;
        }
 
        x = find(x);
        y = find(y);
  
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        rank.resize(N, 0);
        parent.resize(N, 0);
        
        init();
        
        for (int i=0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (M[i][j] == 1) {
                    merge(i, j);
                }
            }
        }
        
        for(int i=0; i < N; i ++) {
            find(i);
        }
   
        sort(parent.begin(), parent.end());
        auto pos = unique(parent.begin(), parent.end());
        return int(pos - parent.begin());
        
    }
private:
    vector<int> rank;
     vector<int> parent;
};