class Solution {
public:
    int power(int m, vector<int> g) {
        int ans = 0;
        int n = g.size();
        for(int i=0;i<n;i++) {
            ans += i*pow(2,n-i-1);
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++) {
            if(grid[i][0]==0) {
                for(int j=0;j<n;j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        for(int j=1;j<n;j++) {
            int cnt = 0;
            for(int i=0;i<m;i++) {
                cnt += (grid[i][j]==0);
            }
            if(m-cnt < cnt) {
                for(int i=0;i<m;i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans = ans + grid[i][j]*pow(2,n-j-1);
            }
        }
        return ans;
    }
};