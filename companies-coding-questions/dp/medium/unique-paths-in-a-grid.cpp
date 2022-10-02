int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if(A[0][0]==1)
        return 0;
    dp[0][0] = 1;
    for(int i=1;i<m;i++) {
        if(A[0][i]==0) {
            dp[0][i] = 1;
        } else {
            break;
        }
    }

    for(int i=1;i<n;i++) {
        if(A[i][0]==0) {
            dp[i][0] = 1;
        } else {
            break;
        }
    }

    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(A[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[n-1][m-1];
}
