class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m);
        vector<vector<int>> ans(m);
        for(int i=0;i<m;i++) {
            prefix[i].resize(n,0);
            ans[i].resize(n,0);
        }
        prefix[0][0] = mat[0][0];
        for(int i=1;i<m;i++) {
            prefix[i][0] = mat[i][0] + prefix[i-1][0];
        }
        for(int i=1;i<n;i++) {
            prefix[0][i] = mat[0][i] + prefix[0][i-1];
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] + mat[i][j] - prefix[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int p = max(0, i-K);
                int r = min(m-1, i+K);
                int q = max(0, j-K);
                int s = min(n-1, j+K);
                if(q-1>=0) {
                    ans[i][j] -= prefix[r][q-1];
                }
                if(p-1>=0) {
                    ans[i][j] -= prefix[p-1][s];
                }
                if(p-1>=0 and q-1>=0) {
                    ans[i][j] += prefix[p-1][q-1];
                }
                ans[i][j] += prefix[r][s];
            }
        }
        return ans;
    }
};