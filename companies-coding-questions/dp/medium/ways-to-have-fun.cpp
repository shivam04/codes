int Solution::solve(int A) {
    vector<vector<long long>> dp(3, vector<long long>(A+1, 0));
    int mod = 1e9 + 7;
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    for(int i = 2; i <= A; i++){
        dp[0][i] = (dp[0][i - 1] % mod + dp[1][i - 1] % mod + dp[2][i - 1] % mod) % mod;
        dp[1][i] = (dp[0][ i - 1] % mod + dp[2][i - 1] % mod);
        dp[2][i] = (dp[0][i - 1] % mod + dp[1][i - 1] % mod - 2 * (dp[2][i - 2]) % mod + mod) % mod;
    } 
    int ans = (dp[0][A] + dp[1][A] + dp[2][A]) % mod;
    return ans;
}
