int maxSum(vector<vector<int> > &A, int i, int j, int n ,int m) {
    if(j==m)
        return 0;
    if(i==n-1)
        return A[i][j];
    if(mp[i][j]!=0)
        return mp[i][j];
    return mp[i][j] = A[i][j] + max(maxSum(A,i+1,j,n,m), maxSum(A,i+1,j+1,n,m));
}
int Solution::solve(vector<vector<int> > &A) {
    mp.clear();
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    for(int i=0;i<m;i++) {
        dp[n-1][i] = A[n-1][i];
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=i;j>=0;j--) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + A[i][j];
        }
    }
    return dp[0][0];
}
