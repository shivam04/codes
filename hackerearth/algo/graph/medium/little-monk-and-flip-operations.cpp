#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int dp[100005][32];
int visit[100005];
int arr[100005];
void dfs(int u){
    visit[u] = 1;
   // cout<<"p "<<u<<"\n";;
    //cout<<"c ";
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        //cout<<v<<" ";
        if(!visit[v]){
            dfs(v);
            for(int j=0;j<32;j++){
                dp[u][j] = max(dp[u][j],dp[v][j]);
            }
        }
    }
   // cout<<"\n";
    for(int j=0;j<32;j++){
        if(dp[u][j] & 1){
            arr[u]^=(1<<j);
        }
        if(arr[u] & (1<<j)){
            dp[u][j]++;
            arr[u]^=(1<<j);
        }
    }
}
int main()
{
    int n,a;
    cin>>n>>a;
    
    int x,y,i;
    memset(visit,0,sizeof(visit));
   // memset(dp,0,sizeof(dp));
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    dfs(a);
    long long ans = 0;
    for(i=0;i<32;i++)
    ans+=dp[a][i];
    cout<<ans<<"\n";
    return 0;
}
