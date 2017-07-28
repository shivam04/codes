#include <bits/stdc++.h>
using namespace std;
int adj[1010][1010],n,m;
int visit[1010][1010];
int solve(int x,int y){
    visit[x][y]=1;
    int i,j;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    int count=1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(i=-1;i<=1;i++){
            for(j=-1;j<=1;j++){
                if(adj[x+i][y+j]==1 and !visit[x+i][y+j]){
                    q.push(make_pair(x+i,y+j));
                    count++;
                    visit[x+i][y+j]=1;
                }
            }
        }
    }
    return count;
}
int main()
{
    int t;
    int i,j;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>adj[i][j];
                visit[i][j]=0;
            }
        }
        int count = 0;
        int ans = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(!visit[i][j]&&adj[i][j]==1){
                    count++;
                    ans = max(solve(i,j),ans);
                }
            }
        }
        cout<<count<<" "<<ans<<"\n";
    }
    return 0;
}