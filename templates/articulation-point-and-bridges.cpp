#include <bits/stdc++.h>
using namespace std;
int g[11][11];
int visit[11]={0};
int parent[11]={-1};
vector<int> ap;
vector<pair<int,int> > bridge;
int disc[11],low[11];
int tim = 0;
void dfs(int u,int n){
    visit[u]=1;
    disc[u]=low[u]=++tim;
    int child = 0;
    int i;
    for(i=0;i<n;i++){
        if(g[u][i]==1){
            if(visit[i]==0){
                child+=1;
                parent[i]=u;
                dfs(i,n);
                low[u] = min(low[u],low[i]);
                if(parent[u]==-1 and child>1)
                ap.push_back(u);
                else if(parent[u]!=-1 and low[i]>=disc[u])
                ap.push_back(u);
                if(low[i]>disc[u]){
                    bridge.push_back(make_pair(min(i,u),max(i,u)));    
                }
                
            }else if(parent[u]!=i){
                low[u] = min(low[u],disc[i]);
            }   
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
        g[a][b]=1;
        g[b][a]=1;
    }
    dfs(0,n);
    cout<<ap.size()<<"\n";
    sort(ap.begin(),ap.end());
    for(i=0;i<ap.size();i++)
    cout<<ap[i]<<" ";
    cout<<"\n";
    sort(bridge.begin(),bridge.end());
    cout<<bridge.size()<<"\n";
    for(i=0;i<bridge.size();i++){
        cout<<bridge[i].first<<" "<<bridge[i].second<<"\n";
    }
    return 0;
}