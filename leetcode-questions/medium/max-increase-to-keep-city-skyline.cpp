class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n,0);
        vector<int> col(n,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                row[i] = max(row[i], grid[i][j]);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                col[i] = max(col[i], grid[j][i]);
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans += (min(row[i], col[j]) - grid[i][j]);
            }
        }

        return ans;
    }
};