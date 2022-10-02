int Solution::climbStairs(int A) {
    int mod = 1000000007;
    vector<int> dp(A+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=A;i++) {
        dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
    }
    return dp[A]%mod;
}
