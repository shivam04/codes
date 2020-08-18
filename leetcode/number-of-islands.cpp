class Solution {
public:
    bool isvalid(int x, int y, int n, int m) {
        return (x>=0 and x<n and y>=0 and y<m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        if(m==0)
            return 0;
        bool visit[n][m];
        memset(visit,false,sizeof(visit));
        int dirx[4] = {1,-1,0,0};
        int diry[4] = {0,0,1,-1};
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visit[i][j] and grid[i][j] == '1') {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    ans++;
                    visit[i][j] = true;
                    while(!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        int x = p.first;
                        int y = p.second;
                        
                        for(int w=0;w<4;w++) {
                            int xx = x+dirx[w];
                            int yy = y+diry[w];
                            if(isvalid(xx,yy,n,m) and grid[xx][yy] == '1' and !visit[xx][yy]) {
                                q.push({xx,yy});
                                visit[xx][yy] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};