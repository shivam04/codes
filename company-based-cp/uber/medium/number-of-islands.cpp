class Solution {
public:
    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,1,-1};
    bool isValid(int x, int y, int n, int m) {
        return (x>=0 and x<n and y>=0 and y<m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool visit[n][m];
        int ans = 0;
        memset(visit,false,sizeof(visit));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (!visit[i][j] and grid[i][j] == '1') {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    ans++;
                    visit[i][j] = true;
                    while(!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        int x = t.first;
                        int y = t.second;
                        visit[x][y] = true;
                        for (int i=0;i<4;i++) {
                            int dx = x + dirx[i];
                            int dy = y + diry[i];
                            if (isValid(dx, dy, n, m) and grid[dx][dy] == '1' 
                                        and !visit[dx][dy]) {
                                visit[dx][dy] = true;
                                q.push({dx, dy});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};