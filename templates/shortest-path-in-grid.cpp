class Solution {
public:
    bool isInsideGrid(int a,int b, int n, int m) {
        return (a >= 0 && a < n && b >= 0 && b < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        multiset<pair<int, pair<int,int>>> s;
        
        int dis[n+1][m+1]; 
        int dx[] = {-1, 0, 1, 0}; 
        int dy[] = {0, 1, 0, -1}; 
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                dis[i][j] = INT_MAX;
            }
        }
        dis[0][0] = heights[0][0]; 
        s.insert({0,{0,0}});
        while(!s.empty()) {
            pair<int,pair<int,int>> t = *s.begin();
            s.erase(s.begin()); 
            int x = t.second.first;
            int y = t.second.second;
            for(int i=0;i<4;i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(!isInsideGrid(xx, yy,n,m)) {
                    continue;
                }
                if(dis[xx][yy] > dis[x][y] + heights[xx][yy]) {
                    if (dis[xx][yy] != INT_MAX) {
                        s.erase(s.find({dis[xx][yy],{xx,yy}}));
                    }
                    dis[xx][yy] = dis[x][y] + heights[xx][yy];
                    s.insert({dis[xx][yy],{xx,yy}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};