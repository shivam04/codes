class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int ans = -1;
        int n = A.size();
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++) {
            int curMax = 0;
            for(int k = 1; k<=K and i-k+1>=0;k++) {
                curMax = max(curMax, A[i-k+1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax*k);
            }
        }
        return dp[n-1];
    }
};