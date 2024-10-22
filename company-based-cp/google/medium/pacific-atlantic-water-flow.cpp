class Solution {
public:
    int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<bool>> bfs(vector<vector<int>>& heights, queue<pair<int,int>> q, int n, int m) {
        vector<vector<bool>> flow(m, vector<bool>(n, false));

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            flow[cur.first][cur.second] = true;

            for (int i=0;i<4;i++) {
                int x = cur.first + dir[i][0];
                int y = cur.second + dir[i][1];
                if ( x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                if (flow[x][y]) {
                    continue;
                }

                if (heights[x][y] < heights[cur.first][cur.second]) {
                    continue;
                }

                q.push({x,y});
            }
        }

        return flow;

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;

        for (int i=0;i<m;i++) {
            pacificQueue.push({i,0});
            atlanticQueue.push({i, n-1});
        }

        for (int i=0;i<n;i++) {
            pacificQueue.push({0,i});
            atlanticQueue.push({m-1, i});
        }

        vector<vector<bool>> pacificFlow = bfs(heights, pacificQueue, n, m);
        vector<vector<bool>> atlanticFlow = bfs(heights, atlanticQueue, n, m);

        vector<vector<int>> commonFlow;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (pacificFlow[i][j] and atlanticFlow[i][j]) {
                    commonFlow.push_back({i,j});
                }
            }
        }
        return commonFlow;
    }
};