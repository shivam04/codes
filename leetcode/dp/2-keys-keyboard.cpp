class Solution {
public:
    int minSteps(int n) {
        if (n<=1)
            return 0;
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 2; i <= n; ++i) {
            for (int j = i / 2; j > 2; --j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + i / j;
                    break;
                }
            }
        }
        return dp[n];
    }
};