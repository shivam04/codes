class Solution {
public:
    vector<vector<int>> dp;
    int getMinValue(int i, int b, int r, int m) {
        int q = dp[i][b];
        int s = (r>=m) ? INT_MAX : dp[i][r];
        return min(q,s);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n);
        for(int i=0;i<triangle[n-1].size();i++) {
            dp[n-1].push_back(triangle[n-1][i]);
        }

        for(int i=n-2;i>=0;i--) {
            int m = triangle[i].size();
            for(int j=0;j<m;j++) {
                dp[i].push_back(getMinValue(i+1,j,j+1,m+1) + triangle[i][j]);
            }
        }
        return dp[0][0];
    }
};