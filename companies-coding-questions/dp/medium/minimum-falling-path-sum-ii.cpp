int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = A[0][0];
    for(int i=1;i<m;i++) {
        dp[0][i] = A[0][i];
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            dp[i][j] = A[i][j];
            int mini = INT_MAX;
            for(int k=0;k<m;k++) {
                if(k!=j)
                    mini = min(mini, dp[i-1][k]);
            }
            dp[i][j] += mini;
        }
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}
