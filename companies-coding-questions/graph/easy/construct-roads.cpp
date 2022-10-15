int Solution::solve(int A, vector<vector<int> > &B) {
    if(A==1)
        return 0;
    vector<int> color(A+1, -1);
    int mod = 1e9+7;
    map<int, vector<int>> mp;
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
    
    vector<long> ccolor(2,0);
    for(int i=1;i<=A;i++) {
        ccolor[color[i]]++;
    }
    return (ccolor[0]%mod * ccolor[1]%mod - (A%mod - 1 + mod)%mod)%mod;

}
