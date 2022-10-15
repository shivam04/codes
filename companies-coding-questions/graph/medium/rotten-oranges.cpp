int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
bool isSafe(int i, int j, int n, int m) {
    return (i>=0 and i<n and j>=0 and j<m);
}
bool isdelim(pair<int,int> p) {
    return p.first == -1 and p.second == -1;
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(A[i][j] == 2) {
                q.push({i,j});
            }
        }
    }
    q.push({-1,-1});

    while(!q.empty()) {
        bool flag = false;
        while (!isdelim(q.front())) {
            auto temp = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int x = temp.first + dir[i][0];
                int y = temp.second + dir[i][1];
                if(isSafe(x,y,n,m) and A[x][y]==1) {
                    if (!flag) ans++, flag = true;
                    A[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        q.pop();
        if(!q.empty()) {
            q.push({-1,-1});
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(A[i][j]==1)
                return -1;
        }
    }
    return ans;
}
