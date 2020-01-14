#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector <int > v[n+2];
    multiset<int> s[n+2];
    int t[100003];
    for(int i=0;i<=100002;i++){
        t[i]=1000000000;
    }
    vector<pair<int, int> > edge[m+2];
    int i;
    int a,b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(i+1);
        v[b].push_back(i+1);
        edge[i+1].push_back(make_pair(a,b));
    }
    for(i=0;i<k;i++){
        cin>>a>>b;
        t[b] = a;
    }
    queue<int > q;
    
    int x;
    int dist[n+1];
    int visit[n+1];
    for(i=0;i<=n;i++){
        dist[i]=1000000007;
    }
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(i=0;i<v[x].size();i++){
            if(t[v[x][i]]<=dist[x]){
                continue;
            }
           int ed = v[x][i];
           int fir = edge[ed][0].first;
           int sec = edge[ed][0].second;
           int lo;
           if(x==fir)
           lo=sec;
           else
           lo = fir;
           
            if(dist[lo]>dist[x]+1){
                dist[lo] = dist[x]+1;
                q.push(lo);
            }
        }
    }
    if(dist[n]==1000000007)
    dist[n]=-1;
    cout<<dist[n];
    return 0;
}