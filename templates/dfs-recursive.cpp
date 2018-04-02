vector<int> g[100005];
int visit[100005];
void dfs(int u){
    visit[u] = 1;
    int i;
    for(i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(!visit[v]){
            dfs(v);
        }
    }
}