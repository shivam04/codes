int Solution::minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(2, vector<int>(m+1,0));
    for(int i=0;i<=m;i++) {
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(j==0) {
                dp[i%2][j] = i;
            } else if(A[i-1]==B[j-1]) {
                dp[i%2][j] = dp[(i-1)%2][j-1];
            } else {
                dp[i%2][j] = 1 + min({dp[i%2][j-1], dp[(i-1)%2][j], dp[(i-1)%2][j-1]});
            }
        }
    }
    return dp[n%2][m];
}
