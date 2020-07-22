class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> tb;
        vector<int> lr;
        for(int j=0;j<m;j++) {
            int maxi = 0;
            for(int i=0;i<n;i++) {
                maxi = max(maxi, grid[i][j]);
            }
            tb.push_back(maxi);
        }
        
        for(int i=0;i<n;i++) {
            int maxi = 0;
            for(int j=0;j<m;j++) {
                maxi = max(maxi, grid[i][j]);
            }
            lr.push_back(maxi);
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int p = min(lr[i], tb[j]);
                if(p > grid[i][j]) {
                    res = res + (p-grid[i][j]);
                    grid[i][j] = p;
                }
            }
        }
        return res;
    }
};