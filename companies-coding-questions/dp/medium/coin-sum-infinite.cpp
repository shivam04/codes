int Solution::coinchange2(vector<int> &A, int B) {
    int mod = 1000007;
    int n = A.size();
    vector<long> dp(B+1, 0);
    dp[0] = 1;
    for(int i=0;i<n;i++) {
        for(int j=A[i];j<=B;j++) {
            dp[j] = (dp[j]%mod + dp[j-A[i]]%mod)%mod;
        }
    } 
    return dp[B]%mod;
}
