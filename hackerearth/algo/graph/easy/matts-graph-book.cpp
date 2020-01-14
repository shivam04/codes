#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,a,b;
    int i;
    cin>>n;
    cin>>k;
    vector<int> v[n+1];
    for(i=0;i<k;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>x;
    v[x].clear();
    stack<int> s;
    s.push(0);
    int visit[n+1];
    for(i=0;i<=n;i++){
        visit[i]=0;
    }
    visit[0]=1;
    visit[x] = 1;
    while(!s.empty()){
        int p = s.top();
        //cout<<p<<"\n";
        s.pop();
        for(i=0;i<v[p].size();i++){
            int q = v[p][i];
            //if(q==x)
            //continue;
            if(visit[q]==0){
                s.push(q);
                visit[q]=1;
            }
        }
    }
    int flag = 1;
    for(i=0;i<n;i++){
        if(visit[i]==0){
            //cout<<i<<"\n";
            flag=0;
            break;
        }
    }
    if(flag)cout<<"Connected\n";
    else cout<<"Not Connected\n";
    return 0;
}
