class Solution {
public:
    int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<bool>> bfs(vector<vector<int>>& heights, queue<pair<int,int>> q, int n, int m) {
        vector<vector<bool>> reachable(m, vector<bool>(n, false));

        while(!q.empty()) {
            auto cell = q.front();
            q.pop();
            reachable[cell.first][cell.second] = true;
            for(int i=0;i<4;i++) {
                int x = dir[i][0] + cell.first;
                int y = dir[i][1] + cell.second;
                if ( x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                if (reachable[x][y]) {
                    continue;
                }

                if (heights[x][y] < heights[cell.first][cell.second]) {
                    continue;
                }

                q.push({x , y});
            }
        }
        return reachable;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pacificQeueu, atlanticQueue;
        int m = heights.size();
        int n = heights[0].size();
        for (int i=0;i<m;i++) {
             pacificQeueu.push({i,0});
             atlanticQueue.push({i, n-1});
        }

        for (int i=0;i<n;i++) {
             pacificQeueu.push({0,i});
             atlanticQueue.push({m-1, i} );
        }

        vector<vector<bool>> pr = bfs(heights, pacificQeueu, n, m);
        vector<vector<bool>> ar = bfs(heights, atlanticQueue, n, m);

        vector<vector<int>> commonCell;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (pr[i][j] && ar[i][j]) {
                    commonCell.push_back({i,j});
                }
            }
        }
        return commonCell;
    }
    
};