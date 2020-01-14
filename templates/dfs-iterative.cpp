stack<i32> s;
s.push(u);
i32 i;
visit[u] = 1;
while(!s.empty()){
    i32 p = s.top();
    //cout<<p<<"\n";
    s.pop();
    ff0(i,0,g[p].size()){
        i32 v = g[p][i];
        if(visit[v]==0){
            s.push(v);
            visit[v]=1;
        }
    }
}