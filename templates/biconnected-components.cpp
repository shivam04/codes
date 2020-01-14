#include <bits/stdc++.h>
using namespace std;
int g[11][11];
int visit[11]={0};
int parent[11]={-1};
vector<pair<int,int> > bridge;
stack<pair<int,int> > st;
int disc[11],low[11];
int tim = 0;
int odd=0,even=0;
void dfs(int u,int n){
    visit[u]=1;
    disc[u]=low[u]=++tim;
    int child = 0;
    int i;
    for(i=0;i<n;i++){
        if(g[u][i]==1){
            if(visit[i]==0){
                child+=1;
                st.push(make_pair(u,i));
                parent[i]=u;
                dfs(i,n);
                low[u] = min(low[u],low[i]);
                if(parent[u]==-1 and child>1){
                    set<int> se;
                    while(st.top().first!=u || st.top().second!=i){
                      // cout<<st.top().first<<"--"<<st.top().second<<" ";
                       se.insert(st.top().first);
                       se.insert(st.top().second);
                        st.pop();
                    }
                    se.insert(st.top().first);
                    se.insert(st.top().second);
                   // cout << st.top().first << "--" << st.top().second<< "\n";
                    st.pop();
                    if(se.size()%2==0)
                    even++;
                    else
                    odd++;
                }
                
                else if(parent[u]!=-1 and low[i]>=disc[u]){
                    set<int> se;
                    while(st.top().first!=u || st.top().second!=i){
                      //  cout << st.top().first << "--" << st.top().second<< " ";
                       se.insert(st.top().first);
                       se.insert(st.top().second);
                       st.pop();
                    }
                    se.insert(st.top().first);
                       se.insert(st.top().second);
                       //cout << st.top().first << "--" << st.top().second<< "\n";
                    st.pop();
                    if(se.size()%2==0)
                    even++;
                    else
                    odd++;
                }
                
                
            }else if(parent[u]!=i and disc[i]<low[u]){
                low[u] = min(low[u],disc[i]);
                st.push(make_pair(u,i));
            }   
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int i;
    int a,b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
    for(i=0;i<n;i++){
        if(visit[i]==0)
        dfs(i,n);
        set<int> se;
        int f = 0;
        while(st.size()>0){
        //cout << st.top().first << "--" << st.top().second<< " ";
        se.insert(st.top().first);
        se.insert(st.top().second);
        st.pop();
        
        f=1;
        
        }
        if(f==1){
           // cout<<"\n";
        if(se.size()%2==0)
        even++;
        else
        odd++;
        }
    }
    
    

    
    cout<<odd<<" "<<even<<"\n";
    return 0;
}