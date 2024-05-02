class Solution {
public:
    vector<vector<int>> dp;
    int getMin(int i, int l, int r, int m) {
        int p = dp[i][l];
        int q = (r>=m) ? INT_MAX : dp[i][r];
        return min(p,q);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n);
        int m = triangle[n-1].size();
        for(int i=0;i<m;i++) {
            dp[n-1].push_back(triangle[n-1][i]);
        }

        for(int i=n-2;i>=0;i--) {
            m = triangle[i].size();
            for(int j=0;j<m;j++) {
                dp[i].push_back(getMin(i+1,j,j+1,m) + triangle[i][j]);
            }
        }
        return dp[0][0];
    }
};