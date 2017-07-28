#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,i,x,y;
    cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        vector <int> v[n+1];
        for(i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        queue <int> q;
        //int count = 0;
        q.push(1);
        int distance[n+1];
        for(i=0;i<=n;i++)
        distance[i]=1000000000;
        distance[1]=0;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(i=0;i<v[val].size();i++){
                //cout<<v[val][i]<<" "<<distance[v[val][i]]<<" "<<distance[val]<<"\n";
                if(distance[v[val][i]]>distance[val]+1){
                    distance[v[val][i]]=distance[val]+1;
                    q.push(v[val][i]);
                }
            }
        }
        cout<<distance[n]<<"\n";
    }
    return 0;
}