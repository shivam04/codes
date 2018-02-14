#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100005];
int visited[100005];
long long cost1[100005];
long long cost2[100005];
long long subn[100005];
int N;
void dfs1(int x){
    visited[x]=1;
    subn[x]=0;
    //cout<<x<<"\n";
    for(int i=0;i<g[x].size();i++){
        int y = g[x][i].first;
        int w = g[x][i].second;
        if(!visited[y]){
            //cout<<y<<" ";
            dfs1(y);
            subn[x]+=subn[y];
            cost1[x] += cost1[y] + ((long long)w)*subn[y];
            //cout<<x<<" "<<cost1[x]<<" "<<subn[x]<<" "<<y<<" "<<cost1[y]<<" "<<subn[y]<<"\n";
        }
        
    }
    
    //cout<<"\n";
    subn[x]++;
}
void dfs2(int x){
    if(x==1){
       cost2[x] = cost1[x];
    }
    visited[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y = g[x][i].first;
        int w = g[x][i].second;
        if(!visited[y]){
            cost2[y] = cost1[y] + (cost2[x]-cost1[y]-((long long)w)*subn[y])+ ((long long)N - subn[y])*w;
            dfs2(y);
        }
    }
    
}
int main() {
    int t;
    int n;
    cin>>t;
    while(t--){
        int n;
        int i;
        cin>>n;
        N = n;
        int a,b,c;
        for(int i=1;i<=100000;i++){
            g[i].clear();
            cost1[i] = 0;
            cost2[i] = 0;
        }
        for(i=0;i<n-1;i++){
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        memset(visited,0,sizeof(visited));
        dfs1(1);
        memset(visited,0,sizeof(visited));
        dfs2(1);
        
        for(int i=1;i<=n;i++){
            cout<<cost2[i]<<"\n";
        }
    }
    
    return 0;
}
