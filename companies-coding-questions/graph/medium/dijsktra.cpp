vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    vector<int> dist(A, INT_MAX);
    unordered_map<int, vector<pair<int,int>>> g;
    for(auto edge: B) {
        g[edge[0]].push_back({edge[2], edge[1]});
        g[edge[1]].push_back({edge[2], edge[0]});
    }
    minHeap.push({0, C});
    dist[C] = 0;
    while(!minHeap.empty()) {
        auto temp = minHeap.top();
        minHeap.pop();
        int x = temp.second; int wei = temp.first;
        for(auto nei: g[x]) {
            int y = nei.second;
            int weight = nei.first;
            if(dist[y] > dist[x] + weight) {
                dist[y] = dist[x] + weight;
                minHeap.push({dist[y], y});
            }
        }
    }
    for(int i=0;i<A;i++) {
        if(dist[i]==INT_MAX)
            dist[i] = -1;
    }
    return dist;
}