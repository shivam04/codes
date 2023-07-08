class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        int maxv = 0;
        for(int j=0;j<m;j++) {
            dp[0][j] = matrix[0][j]-48;
        }

        for(int i=0;i<n;i++) {
            dp[i][0] = matrix[i][0]-48;
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if (matrix[i][j]-48==1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        maxv = dp[0][0];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                maxv = max(maxv, dp[i][j]);
            }
        }
        return maxv*maxv;
    }
};