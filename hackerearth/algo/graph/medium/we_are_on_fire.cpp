#include <bits/stdc++.h>
using namespace std;
int adj[1010][1010],n,m,q;
int visit[1010][1010];
int c = 0;
void solve(int x,int y){
    visit[x][y]=1;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    int count=1;
    c--;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
       //cout<<"main"<<x<<" "<<y<<"\n";
        q.pop();
        if(x-1>=1){
            if(adj[x-1][y]==1 and !visit[x-1][y]){
              //  cout<<x-1<<" "<<y<<"\n";
                q.push(make_pair(x-1,y));
                c--;
                count++;
                visit[x-1][y]=1;
            }    
        }
        if(x+1<=n){
            if(adj[x+1][y]==1 and !visit[x+1][y]){
               // cout<<x+1<<" "<<y<<"\n";
                q.push(make_pair(x+1,y));
                count++;
                c--;
                visit[x+1][y]=1;
            }    
        }
        if(y-1>=0){
            if(adj[x][y-1]==1 and !visit[x][y-1]){
               // cout<<x<<" "<<y-1<<"\n";
                q.push(make_pair(x,y-1));
               count++;
               c--;
                visit[x][y-1]=1;
            }    
        }
        if(y+1<=m){
            if(adj[x][y+1]==1 and !visit[x][y+1]){
              // cout<<x<<" "<<y+1<<"\n";
                q.push(make_pair(x,y+1));
                count++;
                c--;
                visit[x][y+1]=1;
            }    
        }
        
    }
    //cout<<c<<"\n";
   // return count;
}
int main()
{
    //int t;
    //int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    
    int i,j;
    //int ad[n+2][m+2];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&adj[i][j]);
            c+=adj[i][j];
            visit[i][j]=0;
           // ans[i][j] = 0;
        }
    }
    //cout<<"C"<<c<<"\n";
    //int ans=0;
    int x,y;
    for(i=1;i<=q;i++){
        scanf("%d %d",&x,&y);
        //ans = 0;
        if(adj[x][y]==1&&!visit[x][y])
        solve(x,y);
        
        printf("%d\n",c);
        //c-=ans;
    }
    return 0;
}
