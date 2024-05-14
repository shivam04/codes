class Solution {
public:
    int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    bool inside(int x, int y, int n) {
        return (x >= 0 and x < n and y >= 0 and y < n);
    }
    double knightProbability(int n, int k, int row, int column) {
        double dp[n][n][k+1];

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j][0] = 1.0;
            }
        }

        for (int s = 1; s<=k;s++) {
            for(int x = 0;x<n;x++) {
                for (int y=0;y<n;y++) {
                    double prob = 0.0;
                    for(int i=0;i<8;i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (inside(nx, ny, n)) {
                            prob += dp[nx][ny][s-1]/8.0;
                        }
                    }
                    dp[x][y][s] = prob;
                }
            }
        }
        return dp[row][column][k];
    }
};