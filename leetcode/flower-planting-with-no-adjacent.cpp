class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> g[n+1];
        for(int i=0;i<paths.size();i++) {
            g[paths[i][0]].push_back(paths[i][1]);
            g[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> ans(n, 0);
        for(int i=1;i<=n;i++) {
            int cols[5];
            memset(cols,0,sizeof(cols));
            if(g[i].size() ==0 || ans[i-1] != 0)
                continue;
            for(int u : g[i]) {
                if(ans[u-1] != 0)
                    cols[ans[u-1]] = 1;
            }
            for(int c=1;c<=4;c++) {
                if(cols[c]==0) {
                    ans[i-1] = c;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(ans[i]==0)
                ans[i]=1;
        }
        return ans;
    }
};