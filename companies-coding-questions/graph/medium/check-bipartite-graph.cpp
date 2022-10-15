int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> color(A, -1);
    unordered_map<int, vector<int>> mp;
    for(vector<int> e: B) {
        mp[e[0]].push_back(e[1]);
        mp[e[1]].push_back(e[0]);
    }
    for(auto it: mp) {
        if(color[it.first]==-1) {
            int src = it.first;
            color[src] = 1;
            queue <int> q;
            q.push(src);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v: mp[u]) {
                    if(u==v)
                        return 0;
                    if(color[v]==-1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if(color[v]==color[u]){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
