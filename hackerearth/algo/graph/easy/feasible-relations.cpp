#include <bits/stdc++.h>
using namespace std;
vector<int> eq[1000005];
vector<int> neq[1000005];
int evisit[1000005];
int nevisit[1000005];
int cid[1000005];
void dfs1(int x,int id){
    //cout<<x<<"\n";
    evisit[x]=1;
    //if(eq[x].size()==0)
    //evisit[x]=0;
    cid[x]=id;
    int i;
    for(i=0;i<eq[x].size();i++){
        if(!evisit[eq[x][i]])
        dfs1(eq[x][i],id);
    }
}
int dfs2(int x,int p){
    //cout<<x<<" "<<evisit[x]<<" "<<p<<" "<<evisit[p]<<"\n";
    if(cid[x]== cid[p])
    return 0;
    nevisit[x]=1;
    int k,i;
    for(i=0;i<neq[x].size();i++){
        if(!nevisit[neq[x][i]]){
            k = dfs2(neq[x][i],x);
           // cout<<"k= "<<k<<"\n";
            if(!k)
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m;
    int t,j;
    cin>>t;
    while(t--){
        memset(evisit,0,sizeof(evisit));
        memset(nevisit,0,sizeof(nevisit));
        for(n=0;n<1000005;n++){
            eq[n].clear();
            neq[n].clear();
        }
        cin>>n>>m;
        int i,a,b;
        string s;
        for(i=0;i<m;i++){
            cin>>a>>s>>b;
            //cout<<a<<" "<<b<<"\n";
            if(s[0]=='='){
                //cout<<s[0]<<"\n";
                eq[a].push_back(b);
                eq[b].push_back(a);
            }else{
                neq[a].push_back(b);
                neq[b].push_back(a);
            }
        }
       /* for(i=1;i<=n;i++){
            cout<<i<<"\n";
            for(j=0;j<eq[i].size();j++){
                cout<<eq[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        for(i=1;i<=n;i++){
            if(!evisit[i])
            dfs1(i,i);
        }
        
        int flag;
        for(i=1;i<=n;i++){
            if(!nevisit[i]){
                flag = dfs2(i,0);
                if(!flag)
                break;
            }
            
        }
        if(!flag)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
    return 0;
}
