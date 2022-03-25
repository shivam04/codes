bool safe(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}
void bfs(vector<vector<int> > &A, vector<int> x, vector<int> y, queue<pair<int, int>> qu, vector<vector<bool>> &vis){
    int n = A.size();
    int m = A[0].size();
    while(qu.empty()==false){
        pair<int, int> pa = qu.front();
        qu.pop();
        vis[pa.first][pa.second] = true;
        for(int i=0;i<4;i++){
            int nx = pa.first+x[i];
            int ny = pa.second+y[i];
            if(safe(nx, ny, n, m) && A[nx][ny]>=A[pa.first][pa.second] && vis[nx][ny]==false){
                qu.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<int> x = {0, 0, -1, 1};
    vector<int> y = {1, -1, 0, 0};
    queue<pair<int, int>> red, blue;
    vector<vector<bool>> r(n, vector<bool>(m, false));
    vector<vector<bool>> b(n, vector<bool>(m, false));
    for(int i=0;i<m;i++){
        blue.push({0, i});
        red.push({n-1, i});
    }
    for(int j=1;j<n;j++) blue.push({j,0});
    for(int j=0;j<n-1;j++) red.push({j, m-1});
    bfs(A, x, y, blue, b);
    bfs(A, x, y, red, r);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(r[i][j] && b[i][j]) ans++;
        }
    }
    return ans;
}


//Asked in Google