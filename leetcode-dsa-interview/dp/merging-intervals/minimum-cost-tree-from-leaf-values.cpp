class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        // dp[i][j] := the minimum cost of arr[i..j]
        vector<vector<int>> dp(n, vector<int>(n));
        // maxVal[i][j] := the maximum value of arr[i..j]
        vector<vector<int>> maxVal(n, vector<int>(n));

        for (int i=0;i<n;i++) {
            maxVal[i][i] = arr[i];
        }

        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; ++i) {
                int  j = i+len;
                maxVal[i][j] = max(maxVal[i][j-1], maxVal[i+1][j]);
            }
        }

        for (int len=1; len<n; len++) {
            for (int i=0;i+len<n;i++) {
                int j = i+len;
                dp[i][j] = INT_MAX;
                for (int k=i;k<j;k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + maxVal[i][k]*maxVal[k+1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};