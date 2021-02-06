class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector < vector <int> > dp(n, vector <int>(n, 1e7));
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dp[u][v] = w;
            dp[v][u] = w;
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j = 0; j < n; j++) {
                    if(i==j) continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int cnt = INT_MAX;
        int ans;
        for(int i=n-1;i>=0;i--) {
            int temp = 0;
            for(int j = 0; j < n; j++){
                temp += (dp[i][j] <= distanceThreshold);
            }
            if(temp < cnt) {
                cnt = temp;
                ans = i;
            }
        }
        return ans;
    }
};