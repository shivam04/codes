#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int visit[100005];
//int k = 0;
int f = 0;
void dfs(int x){
    visit[x] = 1;
    int i;
    for(i=0;i<g[x].size();i++){
        int y = g[x][i];
        if(!visit[y]){
            dfs(y);
        }
        else if(visit[y]==1)
        f = 1;
    }
    visit[x] = 2;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        f = 0;
        //k=0;
        int n,m;
        int i;
        cin>>n>>m;
        int a,b;
        //memset(visit,0,sizeof(0));
        for(i=0;i<=n;i++){
            g[i].clear();
            visit[i] = 0;
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            g[a].push_back(b);
        }
        
        for(i=1;i<=n;i++){
            if(!visit[i])
            {
                dfs(i);
                if(f){
                    break;
                }
            }
        }
        if(!f)
        cout<<"1\n";
        else
        cout<<"0\n";
        
    }
    return 0;
}
