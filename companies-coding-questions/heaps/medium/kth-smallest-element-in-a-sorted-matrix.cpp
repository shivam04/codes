int Solution::solve(vector<vector<int> > &A, int B) {
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return A[a.first][a.second] > A[b.first][b.second];
    };
    int n = A.size();
    int m = A[0].size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0; i<n; i++){
        pq.push({i,0});
    }

    for(int i=1; i<B; i++){
        auto p = pq.top();
        pq.pop();

        if(p.second+1 < m) pq.push({p.first,p.second + 1});
    }

    return A[pq.top().first][pq.top().second];
}
