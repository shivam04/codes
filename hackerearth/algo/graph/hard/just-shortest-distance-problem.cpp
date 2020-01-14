#include <bits/stdc++.h>
using namespace std;
int dist[1010];
int visit[1010];
vector<int> v[1010];
void ans(int y){
    int i;
    for(i=0;i<v[y].size();i++){
        if(dist[v[y][i]]>dist[y]+1){
            dist[v[y][i]] = dist[y]+1;
            ans(v[y][i]);
        }
    }
}
int main()
{
    int n,m;
    
    cin>>n>>m;
    int i,t,y,x,j;
    for(j=0;j<1010;j++){
        dist[j]=1000000007;
    }
    dist[1]=0;
    for(i=0;i<m;i++){
        cin>>t;
        if(t==1){
            cin>>x;
            if(dist[x]>=1000000007)
            cout<<"-1\n";
            else
            cout<<dist[x]<<"\n";
        }else{
            cin>>x>>y;
            v[x].push_back(y);
            if(dist[y]>dist[x]+1){
                dist[y] = dist[x]+1;
                ans(y);
            }
        }
    }
    return 0;
}