int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    dp[n][m] = 1;
    for (int i = n; i >= 0; i--) {
        for(int j=m-1;j>=0;j--) {
            bool fM = (i < n and (A[i]==B[j] or B[j]=='.'));
            if(j+1<m and B[j+1]=='*') {
                dp[i][j] = (dp[i][j+2] or (fM and dp[i+1][j]));
            } else {
                dp[i][j] = fM && dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];
}
