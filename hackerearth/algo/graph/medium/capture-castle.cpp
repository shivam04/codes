#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long t;
    long long m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        long long i,j,a[m+1][n+1];
        long long dist[m+1][n+1];
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>a[i][j];
                dist[i][j]=1000000000000000007;
            }
        }
        long long p1,q1,w;
        cin>>p1>>q1>>w;
      queue<pair<long long, long long> > q;
      q.push(make_pair(1,1));
      
     // memset(dist,0,sizeof(dist));
     // long long visit[m+1][n+1];
      //memset(visit,0,sizeof(dist));
      dist[1][1]= a[1][1];
      while(!q.empty()){
          pair<long long,long long> k = q.front();
          q.pop();
          long long x = k.first;
          long long y = k.second;
          //visit[k.first][k.second]=1
          if(x-1>=1 and dist[x-1][y]>dist[x][y]+a[x-1][y]){
              dist[x-1][y] = dist[x][y]+a[x-1][y];
              q.push(make_pair(x-1,y));
          }
          if(x+1<=m and dist[x+1][y]>dist[x][y]+a[x+1][y]){
              dist[x+1][y] = dist[x][y]+a[x+1][y];
              q.push(make_pair(x+1,y));
          }
          if(y-1>=1 and dist[x][y-1]>dist[x][y]+a[x][y-1]){
              dist[x][y-1] = dist[x][y]+a[x][y-1];
              q.push(make_pair(x,y-1));
          }
          if(y+1<=n and dist[x][y+1]>dist[x][y]+a[x][y+1]){
              dist[x][y+1] = dist[x][y]+a[x][y+1];
              q.push(make_pair(x,y+1));
          }
      }
      //cout<<dist[p1][q1]<<"\n";
      if(w-dist[p1][q1]>0){
          cout<<"YES\n";
          cout<<w-dist[p1][q1]<<"\n";
      }else{
          cout<<"NO\n";
      }
    }
    return 0;
}