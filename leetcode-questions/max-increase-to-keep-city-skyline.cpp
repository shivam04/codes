class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                row[i] = max(row[i], grid[i][j]);
            }
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                col[i] = max(col[i], grid[j][i]);
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans += (min(row[i], col[j]) - grid[i][j]);
            }
        }
        return ans;
    }
};