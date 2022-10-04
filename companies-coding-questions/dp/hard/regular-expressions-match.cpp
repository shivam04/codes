int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    int dp[2][m+1];
    dp[0][0] = true;
    int h = 1;
    for(int i=1;i<=m;i++) {
        if(B[i-1]=='*' and h==1) {
            dp[0][i] = true;
        }
        else {
            dp[0][i] = false;
            h = 0;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(j==0) {
                dp[i%2][j] = false;
            } else if(A[i-1]==B[j-1] || B[j-1]=='?') {
                dp[i%2][j] = dp[(i-1)%2][j-1];
            } else if(A[i-1]!=B[j-1] and B[j-1]=='*') {
                dp[i%2][j] = dp[i%2][j-1] || dp[(i-1)%2][j];
            } else {
                dp[i%2][j] = false;
            }
        }
    }
    return dp[n%2][m];
}
