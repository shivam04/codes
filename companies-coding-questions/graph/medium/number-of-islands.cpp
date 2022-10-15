int dir[8][2] = {{1,0}, {0,1}, {1,1}, {-1,-1}, {-1,0}, {0,-1}, {1,-1}, {-1, 1}};
bool isSafe(int x, int y, int n, int m) {
    return (x>=0 and x < n and y >= 0 and y < m);
}
void countIsland(vector<vector<int> > &A, int x, int y, vector<vector<int> > &visit, int n, int m) {
    visit[x][y] = 1;
    for(int i=0;i<8;i++) {
        int xx = dir[i][0] + x;
        int yy = dir[i][1] + y;
        if(isSafe(xx, yy, n, m) and visit[xx][yy] == 0 and A[xx][yy]==1) {
            countIsland(A, xx, yy, visit, n, m);
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > visit(n , vector<int>(m, 0));
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(visit[i][j]==0 and A[i][j]==1) {
                countIsland(A, i, j, visit, n, m);
                ans++;
            }
        }
    }
    return ans;
}
