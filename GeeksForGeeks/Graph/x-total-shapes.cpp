#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string s[n+1];
	    for(int i=0;i<n;i++)
	    cin>>s[i];
	    int c = 0;
	    int visit[n][m];
	    memset(visit,0,sizeof(visit));
	    int move[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
    	        if(!visit[i][j] and s[i][j]=='X'){
    	            c++;
    	            queue<pair<int,int>> q;
    	            q.push({i,j});
    	            while(!q.empty()){
    	                pair<int,int> p = q.front();
    	                q.pop();
    	                for(int k=0;k<4;k++){
    	                    int x = p.first+move[k][0];
    	                    int y = p.second+move[k][1];
    	                    if(x>=0 and x<n and y>=0 and y<m and !visit[x][y] and s[x][y]=='X'){
    	                        visit[x][y]=true;
    	                        q.push({x,y});
    	                    }
    	                }
    	            }
    	        }
	        }
	    }
	    cout<<c<<"\n";
	}
	return 0;
}