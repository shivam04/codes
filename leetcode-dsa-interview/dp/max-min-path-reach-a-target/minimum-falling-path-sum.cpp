class Solution {
public:
    int getVal(vector<vector<int>> &dp, int i, int j, int n) {
        if (i < 0 or j < 0 or i >=n or j>=n) {
            return INT_MAX;
        }

        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=0;i<n;i++) {
            dp[0][i] = matrix[0][i];
        }

        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = matrix[i][j] 
                    + min({getVal(dp,i-1,j,n), getVal(dp,i-1,j-1,n), getVal(dp,i-1,j+1,n)});
            }
        }

        int mini = INT_MAX;
        for (int i=0;i<n;i++) {
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};