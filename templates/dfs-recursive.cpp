vi32 g[100005];
i32 visit[100005];
void dfs(i32 u){
    visit[u] = 1;
    //cout<<"p "<<u<<"\n";
    //cout<<"c\n";
    i32 i;
    ff0(i,0,g[u].size()){
        i32 v = g[u][i];
        if(!visit[v]){
            //cout<<v<<"\n";
            dfs(v);
        }
    }
    //cout<<"\n";
}