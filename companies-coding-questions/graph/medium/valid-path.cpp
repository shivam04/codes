int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};
bool isSafe(int i, int j, int n, int m) {
    return (i>=0 and i<=n and j>=0 and j<=m);
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> rect(A+1, vector<int>(B+1,0));
    for (int i=0;i<=A;i++) {
        for(int j=0;j<=B;j++) {
            for (int p=0; p<C; p++) {
                int x = E[p];
                int y = F[p];
                if(sqrt(pow(x-i,2) + pow(y-j, 2)) <= D) {
                    rect[i][j] = -1;
                }
            }
        }
    }
    if (rect[0][0] == -1)
        return "NO";
    queue<pair<int,int>> q;
    q.push({0,0});
    rect[0][0] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for(int i=0;i<8;i++) {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(isSafe(xx,yy,A,B) and rect[xx][yy]==0) {
                rect[xx][yy] = 1;
                q.push({xx,yy});
            }
        }
    }
    return rect[A][B]==1 ? "YES" : "NO";
}
