#include<bits/stdc++.h>
using namespace std;



int main()
{
    int x, y, nodes, edges,k;
    cin >> nodes;
    cin >> edges;
    cin >> k;
    int i;
    vector < pair<int,int> > adj[nodes+1];
    int v[nodes+1];
    v[0] = 0;
    for( i=1;i<=nodes;i++){
        cin>>v[i];
    }
    for( i = 0;i < edges;++i)
    {
            cin >> x >> y;
        adj[x].push_back(make_pair(v[y],y));
        adj[y].push_back(make_pair(v[x],x));
     }
for( i = 1;i <= nodes;++i)
{   
    sort(adj[i].begin(),adj[i].end());
}
for(i=1;i<=nodes;i++){
    if(adj[i].size()>=k){
        cout<<adj[i][adj[i].size()-k].second<<"\n";
    }else{
        cout<<"-1\n";
    }
}
return 0;
}