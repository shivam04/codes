class Solution {
public:
    map<string,int> visit;
    map<string,int> dp;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void flipMatrix(vector<vector<int>>& mat, int x, int y, int n, int m) {
        mat[x][y] = (mat[x][y] == 0 ? 1 : 0);
        for(int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 and xx<n and yy>=0 and yy<m) {
                mat[xx][yy] = (mat[xx][yy] == 0 ? 1 : 0);
            }
        }
    }
    string getKey(vector<vector<int>> &mat, int n, int m) {
        string key = "";
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                key += to_string(i)+":"+to_string(j)+":"+to_string(mat[i][j]);
                if(i==n-1 and j==m-1)
                    continue;
                key+=",";
            }
        }
        return key;
    }
    int dfs(vector<vector<int>> &mat, int n, int m) {
        string key = getKey(mat,n,m);
        if(visit.find(key) != visit.end()) {
            return -1;
        }
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        visit.insert({key,1});
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                flipMatrix(mat, i, j, n, m);
                int mc = dfs(mat,n,m);
                if(mc>=0)
                    ans = min(ans, mc);
                flipMatrix(mat, i, j, n, m);
            }
        }
        visit.erase(key);
        if(ans==INT_MAX)
            return dp[key] = -1;
        return dp[key] = ans+1;
    }
    int minFlips(vector<vector<int>>& mat) {
        visit.clear();
        int n = mat.size();
        int m = mat[0].size();
        string key = "";
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                key += to_string(i)+":"+to_string(j)+":0";
                if(i==n-1 and j==m-1)
                    continue;
                key+=",";
            }
        }
        dp[key] = 0;
        return dfs(mat,n,m);
    }
};