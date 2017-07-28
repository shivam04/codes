#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[100005];
int visit[100005]={0};
int parent[100005]={-1};
set<int> bridge;
int disc[100005],low[100005];
int tim = 0;
void dfs(int u,int n){
    visit[u]=1;
    disc[u]=low[u]=++tim;
    int i;
    for(i=0;i<g[u].size();i++){
        int v = g[u][i].first;
        int edge = g[u][i].second;
        if(visit[v]==0){
            parent[v]=u;
            dfs(v,n);
            low[u] = min(low[u],low[v]);
            if(low[v]>disc[u]){
               // cout<<u<<" "<<v<<"\n";
                bridge.insert(edge);
            }
            
        }else if(parent[u]!=v){
            low[u] = min(low[u],disc[v]);
        }   
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int i;
    int a,b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(make_pair(b,i+1));
        g[b].push_back(make_pair(a,i+1));
    }
    for(i=1;i<=n;i++){
        if(visit[i]==0)
        dfs(i,n);
    }
    
    int q;
    cin>>q;
    int e;
    while(q--){
        cin>>e;
        if(bridge.find(e)!=bridge.end()){
            cout<<"Unhappy";
        }else{
            cout<<"Happy";
        }
        cout<<"\n";
    }
    return 0;
}