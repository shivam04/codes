#define inf 100000000
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(A[i][j] != -1)
                dist[i][j] = A[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(dist[i][j]==inf)
                dist[i][j] = -1;
        }
    }
    return dist;
}
