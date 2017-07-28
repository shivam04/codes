#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
 
#define LEN 1003
bool g[LEN][LEN]={{0}};
bool visited[LEN]={0};
bool girls[LEN]={0};
 
void bfs(int n){
    visited[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int j=0;j<n;j++){
            if(g[i][j] && !visited[j]){
                visited[j]=1;
                if(girls[j]){
                    cout<<j+1<<endl;
                    return;
                }
                q.push(j);
            }
        }
    }
}
 
int main()
{
    int i,j,n,q,u,v;
    cin>>n;
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        //cin>>u>>v;
        g[u-1][v-1]=1;
        g[v-1][u-1]=1;
    }
    cin>>q;
    for(i=0;i<q;i++){
        scanf("%d",&u);
        girls[u-1]=1;
    }
    bfs(n);
    return 0;
}