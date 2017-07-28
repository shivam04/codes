#include <bits/stdc++.h>
using namespace std;
vector<int> g[1004];
int visit[1004];
void dfs(int u){
    visit[u] = 1;
    //cout<<"p "<<u<<"\n";
    //cout<<"c\n";
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(!visit[v]){
            //cout<<v<<"\n";
            dfs(v);
        }
    }
    //cout<<"\n";
}
int main()
{
    int n,d;
    cin>>n>>d;
    int i,x,y;
    for(i=0;i<d;i++){
        cin>>x>>y;
        g[x].push_back(y);
    }
    int mins = 1000000007;
    int j;
    for(i=1;i<=n;i++){
        memset(visit,0,sizeof(visit));
        dfs(i);
        int ans = 0;
        for(j=1;j<=n;j++){
            if(visit[j]==1){
                ans++;
            }
        }
        if(ans<mins)
        mins = ans;
        cout<<"\n";
    }
    cout<<mins<<"\n";
    return 0;
}
