int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>>dp (n+1, vector<int>(n+1,0));
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if (i == 0 or j == 0) {
                    dp[i][j] = 0;
            } else if(i==1) {
                dp[i][j] = j*A[0];
            } else {
                if(i>j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(A[i-1]+dp[i][j-i], dp[i-1][j]);
                }
            }
        }
    }
    return dp[n][n];
}
