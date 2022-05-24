class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        dp[0][0] = !obstacleGrid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i] = (dp[0][i-1] and !obstacleGrid[0][i]);
        }
        for(int i=1;i<n;i++){
            dp[i][0] = (dp[i-1][0] and !obstacleGrid[i][0]);
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n-1][m-1];
    }
};