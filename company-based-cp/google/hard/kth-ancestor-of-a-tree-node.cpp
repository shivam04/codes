class TreeAncestor {
public:
    int n;
    vector<vector<int>> parent;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        this->parent.resize(n, {});
        vector<vector<int>> adj;
        adj.resize(n, {});
        int par = -1;
        int m = ceil(log2(n));
        for (int i=0;i<n;i++) {
            this->parent[i].resize(m+1, -1);
            if (parent[i] == -1) {
                par = i;
                continue;
            }
            adj[parent[i]].push_back(i);
        }
        dfs(par, -1, adj);
    }
    
    int getKthAncestor(int node, int k) {
        int m = log2(n);
        for(int i=log2(n); i>=0; i--) {
            int p = (k&(1<<i));
            if (p != 0 and node != -1) {
                node = parent[node][i];
            }
        }                     
        return node;   
    }
private:
    void dfs(int cur, int par, vector<vector<int>> &adj) {
        parent[cur][0] = par;
        int m = ceil(log2(n));
        for (int i=1;i<m;i++) {
            if (parent[cur][i-1] >= 0)
                parent[cur][i] = parent[parent[cur][i-1]][i-1];
        }

        for (int j: adj[cur]) {
            if (j != par)
                dfs(j, cur, adj);
        }
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */