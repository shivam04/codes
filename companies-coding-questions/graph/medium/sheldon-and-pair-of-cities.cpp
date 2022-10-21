#define inf 100000000
vector<int> Solution::solve(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F, vector<int> &G, vector<int> &H) {
    vector<vector<int>> dist(A, vector<int>(A, inf));
    for(int i=0;i<B;i++) {
        dist[D[i]-1][E[i]-1] = min(dist[D[i]-1][E[i]-1], F[i]);
        dist[E[i]-1][D[i]-1] = min(dist[E[i]-1][D[i]-1], F[i]);
    }
    for(int i=0;i<A;i++) {
        dist[i][i] = 0;
    }

    for(int k = 0; k < A; k++){
        for(int i = 0; i < A; i++){
            for(int j = 0; j < A; j++){
                dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }

    for(int i=0;i<A;i++) {
        for(int j=0;j<A;j++) {
            if(dist[i][j]==inf)
                dist[i][j] = -1;
        }
    }
    vector<int> ans;
    int i = 0;
    while(i < C) {
        ans.push_back(dist[G[i]-1][H[i]-1]);
        i++;
    }
    return ans;
}
