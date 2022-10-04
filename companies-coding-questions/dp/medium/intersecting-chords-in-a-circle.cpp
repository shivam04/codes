int Solution::chordCnt(int A) {
    int mod = 1000000007;
    int n = 2*A;
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    dp[2] = 1;
    for (int i=4;i<=n;i+=2){
        for(int j=0;j<i-1;j+=2) {
            dp[i] = (dp[i]%mod + (dp[j]%mod*dp[i-j-2]%mod)%mod)%mod;
        }
    }
    return dp[n];
}
