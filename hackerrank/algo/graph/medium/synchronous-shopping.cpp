#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second 
vector<pair<int,int>> g[1004];
int ve[1004];
int dist[1004][1024];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int j,i,a,t;
    for(i=1;i<=n;i++){
        cin>>a;
        ve[i] = 0;
        for(j=0;j<a;j++){
            cin>>t;
            t--;
            ve[i]|=(1 << (t));
        }
    }
    int u,v;
    for(i=0;i<m;i++){
        cin>>u>>v>>t;
        g[u].push_back({v,t});
        g[v].push_back({u,t});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1024; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    dist[1][ve[1]] = 0;
    set< pair<int, pair<int, int> > > s;
    s.insert({0,{1,ve[1]}});
    while (!s.empty() ) {
        pair<int, pair<int, int> > cur = *s.begin();
        s.erase(s.begin() );
        int x = cur.s.f, ty = cur.s.s, ct = cur.f;
        for (int j = 0; j < g[x].size(); j++) {
            int y = g[x][j].f;
            int tim = g[x][j].s;
            int tty = ty | ve[y];
            if (dist[y][tty] > ct + tim) {
                s.erase( {dist[y][tty], {y,tty} } );
                dist[y][tty] = ct + tim;
                s.insert( {dist[y][tty], {y,tty} } );
            }
        }
    }
    int ans = INT_MAX;
   // cout<<ans<<"\n";
    for(i=0;i<(1<<k);i++){
         for (j = 0; j < (1<<k); j++) {
             if((i|j)==((1<<k)-1)){
                 ans = min(ans,max(dist[n][i],dist[n][j]));
             }
         }
    }
    cout<<ans<<"\n";
    return 0;
}
