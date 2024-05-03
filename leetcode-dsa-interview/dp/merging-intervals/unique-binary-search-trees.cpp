// O(N^2)
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        fill_n(dp, n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                dp[i] = dp[i] + (dp[j-1]*dp[i-j]);
            }
        }
        return dp[n];
    }
};

// O(N)

class Solution {
public:
    int numTrees(int n) {
        // Note: we should use long long here instead of int, otherwise overflow
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};