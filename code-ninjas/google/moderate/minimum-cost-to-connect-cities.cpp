#include<bits/stdc++.h>
typedef pair<int, int> iPair;
vector<vector<int>> findMST(vector<vector<int>> &road, int n, int m) {
    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1, -1);
    vector<bool> inMST(n+1, false);
    vector<iPair> adj[n+1];
    
    for(vector<int> r: road) {
        int u = r[0] - 1;
        int v = r[1] - 1;
        int w = r[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    dist[0] = 0;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    pq.push({0,0});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(inMST[u] == true){
            continue;
        }
        inMST[u] = true;
        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(inMST[v]==false and dist[v]>w) {
                dist[v] = w;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
    vector<vector<int>> ans;
    for(int i=0;i<n;i++) {
        if(parent[i]!=-1)
        ans.push_back({parent[i]+1,i+1,dist[i]});
    }
    return ans;
}
