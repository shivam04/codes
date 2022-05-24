class Solution {
public:
    int dp[72][72][72];
    int cherryPickupUtil(int row, int c1, int c2, vector<vector<int>>& grid) {
        if(c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size()) {
            return 0;
        }
        if(dp[row][c1][c2] != -1)
            return dp[row][c1][c2];
        int res = 0;
        res += grid[row][c1];
        if(c1!=c2) {
            res += grid[row][c2];
        }
        if(row!=grid.size()-1) {
            int maxi = 0;
            for(int nc1=c1-1;nc1<=c1+1;nc1++) {
                for(int nc2=c2-1;nc2<=c2+1;nc2++) {
                    maxi = max(maxi, cherryPickupUtil(row+1,nc1,nc2,grid));
                }
            }
            res += maxi;
        }
        return dp[row][c1][c2]=res;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();
        return cherryPickupUtil(0,0,n-1,grid);
    }
};