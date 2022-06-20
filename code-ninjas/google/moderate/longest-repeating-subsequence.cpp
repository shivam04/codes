int longestRepeatingSubsequence(string st, int n) {
	int dp[n+1][n+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0 or j==0) {
                dp[i][j] = 0;
            }else if(i != j and st[i-1]==st[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

