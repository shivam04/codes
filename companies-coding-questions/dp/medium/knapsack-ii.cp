int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<vector<int>> dp(2, vector<int>(C+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=C;j++) {
            if(j < B[i-1]) {
                dp[i%2][j] = dp[(i-1)%2][j];
            } else {
                dp[i%2][j] = max(A[i-1] + dp[(i-1)%2][j-B[i-1]], dp[(i-1)%2][j]);
            }
        }
    }
    return dp[n%2][C];
}
