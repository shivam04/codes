class Solution {
public:
    bool isInsideGrid(int a,int b, int n, int m) {
        return (a >= 0 && a < n && b >= 0 && b < m);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int p = 0;
        int n = grid.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0)
                    p++;
            }
        }
        if(p==0 || p==n*n)
            return -1;
        queue<pair<int,int>> q, pq;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        int dx[] = {-1, 0, 1, 0}; 
        int dy[] = {0, 1, 0, -1}; 
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i=0;i<4;i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(isInsideGrid(xx,yy,n,n) and !grid[xx][yy]) {
                    grid[xx][yy] = 1;
                    pq.push({xx,yy});
                }
            }
            if(q.empty()) {
                swap(q, pq);
                ans++;
            }
        }
        return ans-1;
    }
};