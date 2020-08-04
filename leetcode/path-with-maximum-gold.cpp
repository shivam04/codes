class Solution {
public:
    int DFS(vector<vector<int>>& grid,int x,int y){
        int cur_gold=grid[x][y];
        grid[x][y]=0;
        int max_gold=0;
        if(x && grid[x-1][y]) max_gold=max(max_gold,DFS(grid,x-1,y));
        if(y && grid[x][y-1]) max_gold=max(max_gold,DFS(grid,x,y-1));
        if(x+1<grid.size() && grid[x+1][y]) max_gold=max(max_gold,DFS(grid,x+1,y));
        if(y+1<grid[0].size() && grid[x][y+1]) max_gold=max(max_gold,DFS(grid,x,y+1));
        grid[x][y] = cur_gold;
        return cur_gold+ max_gold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = -1;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]) {
                    ans = max(ans,DFS(grid,i,j));
                }
            }
        }
        return ans;
    }
};