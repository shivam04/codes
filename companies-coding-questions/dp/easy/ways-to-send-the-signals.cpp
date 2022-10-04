int mod = 1000000007;
int Solution::solve(int A) {
    vector<vector<int>> dp(2, vector<int>(A+1,0));
    dp[0][0] = 1;
    dp[1][0] = 0;
    for(int i=1;i<=A;i++) {
        dp[0][i] = (dp[1][i-1]%mod + dp[0][i-1]%mod)%mod;
        dp[1][i] = dp[0][i-1]%mod;
    }
    return (dp[0][A]%mod + dp[1][A]%mod)%mod;
}
