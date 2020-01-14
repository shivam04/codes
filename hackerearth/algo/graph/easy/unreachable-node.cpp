#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int i;
    vector<int> g[n+1];
    int x,a,b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>x;
    stack<int> s;
    s.push(x);
    int visit[n+1];
    for(i=0;i<=n;i++)
    visit[i]=0;
    visit[x]=1;
    while(!s.empty()){
        int k = s.top();
        s.pop();
        
        for(i=0;i<g[k].size();i++){
            int q = g[k][i];
            if(visit[q]==0){
                s.push(q);
                visit[q]=1;
            }
        }
    }
    int ans = 0;
    for(i=1;i<=n;i++){
        if(visit[i]==0)
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
