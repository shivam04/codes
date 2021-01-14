int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    B = min(B,n);
    vector<vector<int>> dp(B+1,vector<int>(n+1,0));
    for(int i=1;i<=B;i++) {
        int pd = INT_MIN;
        for(int j=1;j<n;j++) {
            pd = max(pd, dp[i-1][j-1] - A[j-1]);
            dp[i][j] = max(dp[i][j-1], pd+A[j]);
        }
    }
    return dp[B][n-1];
}
