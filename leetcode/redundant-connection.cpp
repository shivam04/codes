class Solution {
public:
    vector<int> id;
    int root(int x) {
        while(id[x] != x) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }

    void union1(int x, int y) {
        int p = root(x);
        int q = root(y);
        id[p] = id[q];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        id.resize(n+1);
        for(int i=0;i<n+1;i++) {
            id[i] = i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int p = edges[i][0];
            int q = edges[i][1];
            if(root(p) != root(q)) {
                union1(p,q);
            } else {
                ans.push_back(p);
                ans.push_back(q);
                return ans;
            }
        }
        return ans;
    }
};