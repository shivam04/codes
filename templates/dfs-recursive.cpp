vector<int> g[100005];
int visit[100005];
void dfs(int u){
    visit[u] = 1;
    //cout<<"p "<<u<<"\n";
    //cout<<"c\n";
    int i;
    ff0(i,0,g[u].size()){
        int v = g[u][i];
        if(!visit[v]){
            //cout<<v<<"\n";
            dfs(v);
        }
    }
    //cout<<"\n";
}