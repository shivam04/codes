#include <bits/stdc++.h>
using namespace std;
 int visit[100005];
 int p[100005],q[100005];
 int n;
 vector<int> A,B;
 vector<int> g[100005];
void bfs(int i){
    queue <int> qe;
    qe.push(i);
    while(!qe.empty()){
        int k = qe.front();
        qe.pop();
        A.push_back(p[k]);
    B.push_back(q[k]);
        visit[k] = 1;
        for(int i=0;i<g[k].size();i++){
            if(!visit[g[k][i]]){
                qe.push(g[k][i]);
                visit[g[k][i]]=1;
            }    
        }  
    }
}
int main()
{
    int t;
    int m,a,b,i;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=0;i<n;i++){
            visit[i]=0;
            g[i].clear();
        }
        for(i=0;i<n;i++)
        cin>>p[i];
        for(i=0;i<n;i++)
        cin>>q[i];
        for(i=0;i<m;i++){
            cin>>a>>b;
            --a;
            --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int flag = 1;
        for(i=0;i<n;i++){
            A.clear();
            B.clear();
            if(!visit[i]){
                bfs(i);
                sort(A.begin(),A.end());
                sort(B.begin(),B.end());
                if(A!=B)
                flag = 0;
            }
            if(flag==0)
            break;
        }
        if(flag)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}
