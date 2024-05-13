class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[n][n];
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (j < i+2) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k=i+1;k<j;k++) {
                        int val = dp[i][k] + dp[k][j] + values[i]*values[k]*values[j];
                        dp[i][j] = min(dp[i][j], val);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};