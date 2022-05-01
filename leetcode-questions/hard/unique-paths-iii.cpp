class Solution {
public:
    int ans = 0;
    void dfs(int i, int j, vector<vector<int>> grid, int empty, int m, int n) {
        if(i<0 or j<0 or i >= m or j >= n or 
           grid[i][j] == -1 or grid[i][j] == 10) return;
        if(grid[i][j]==2 and empty==0) ans++;
        if(grid[i][j]==0) --empty;
        int temp = grid[i][j];
        grid[i][j] = 10;
        
        dfs(i-1,j,grid,empty,m,n);
        dfs(i+1,j,grid,empty,m,n);
        dfs(i,j-1,grid,empty,m,n);
        dfs(i,j+1,grid,empty,m,n);
        grid[i][j] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        int m = grid.size();
        int n = grid[0].size();
        int empty = 0;
        ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    startX = i;
                    startY = j;
                }
                empty += (grid[i][j]==0);
            }
        }
        dfs(startX, startY, grid, empty,m ,n);
        return ans;
    }
};