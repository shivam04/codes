class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int ans[n+1][m+1];
        int minPath = INT_MAX;
        for(int i=0;i<m;i++)
            ans[0][i] = A[0][i];
        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j] = INT_MAX;
                if(i>0)
                    ans[i][j] = min(ans[i][j], ans[i-1][j]);
                if(i>0 and j>0)
                    ans[i][j] = min(ans[i][j], ans[i-1][j-1]);
                if(i>0 and j<m-1)
                    ans[i][j] = min(ans[i][j], ans[i-1][j+1]);
                ans[i][j] += A[i][j];
            }
        }
        for(int i=0;i<m;i++) {
            minPath = min(minPath, ans[n-1][i]);
        }
        return minPath;
    }
};