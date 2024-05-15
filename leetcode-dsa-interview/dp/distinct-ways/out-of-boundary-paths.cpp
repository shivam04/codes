class Solution {
public:
    int mod = 1e9+7;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool outside(int x, int y, int m, int n) {
        return !(x >= 0 and x < m and y >= 0 and y < n);
    }
    int dp[51][51][55];
    int findPathsUtil(int m, int n, int maxMove, int startRow, int startColumn) {
        if (outside(startRow, startColumn, m, n)) {
            return 1;
        }

        if (maxMove == 0) {
            return 0;
        }

        if (dp[startRow][startColumn][maxMove] != -1) {
            return dp[startRow][startColumn][maxMove];
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int x = startRow + dx[i];
            int y = startColumn + dy[i];
            ans = (ans%mod + findPathsUtil(m, n, maxMove-1, x, y)%mod)%mod;
        }
        return dp[startRow][startColumn][maxMove] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return findPathsUtil(m, n, maxMove, startRow, startColumn);
    }
};