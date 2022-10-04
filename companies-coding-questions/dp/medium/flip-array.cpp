int Solution::solve(const vector<int> &A) {
    int n = A.size();
    unordered_map<int,int> dp[n+1];
    bool flag = 1;
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += A[i];
    }

    int halfSum = sum/2;

    for(int i=0;i<=halfSum;i++) {
        dp[0][i] = INT_MAX-1;
    }

    dp[0][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=halfSum;j++) {
            dp[i][j] = (j >= A[i-1]) ? min(dp[i-1][j], dp[i-1][j - A[i-1]] + 1) : dp[i-1][j];
        }
    }
    while(halfSum > 0  &&  dp[n][halfSum] >= (INT_MAX-1))
        halfSum--;
    return dp[n][halfSum];
}
