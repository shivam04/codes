#define inf 1e5
typedef pair<int,pair<int,int>> PIPII;
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
bool isSafe(int i, int j, int n, int m) {
    return (i>=0 and i<n and j>=0 and j<m);
}
int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dist(n, vector<int>(m, inf));
    int sD = inf;
    priority_queue<PIPII, vector<PIPII>, greater<PIPII>> pq;
    pq.push({0, {B[0], B[1]}});
    while(!pq.empty()) {
        PIPII temp = pq.top();
        pq.pop();
        int x = temp.second.first;
        int y = temp.second.second;
        int distance = temp.first;
        for(int i=0;i<4;i++) {
            int dx = dir[i][0];
            int dy = dir[i][1];
            int time = 0;
            int sx = x;
            int sy = y;
            int cx = x + dx;
            int cy = y + dy;
            while(isSafe(cx, cy, n, m) and A[cx][cy] == 0) {
                time++;
                sx = cx;
                sy = cy;
                if(x==C[0] and y==C[1]) {
                    int newDistance = distance + time;
                    if(newDistance < sD) {
                        sD = newDistance;
                        dist[x][y] = sD;
                    }
                    break;
                }
                cx += dx;
                cy += dy;
            }
            int newDistance = distance + time;
            if(newDistance < dist[sx][sy]) {
                dist[sx][sy] = newDistance;
                pq.push({newDistance, {sx, sy}});
            }
        }
    }
    return sD == inf ? -1 : sD-1;
}
