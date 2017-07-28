#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,i,x,y;
    int n,m;
        cin>>n>>m;
        vector <int> v[n+1];
        for(i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        queue <int> q;
        //int count = 0;
        q.push(0);
        int distance[n+1];
        for(i=0;i<=n;i++)
        distance[i]=1000000000;
        distance[0]=0;
       // cout<<q.empty()<<"\n";
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
      for(i=1;i<n;i++){
          cout<<distance[i]<<"\n";
      }
    return 0;
}