#include<bits/stdc++.h>
using namespace std;
int visit[55][55];
int h[55][55];
const int inf = 0x3f3f3f3f; 
int dx[4] = {0,0,1,-1};  
int dy[4] = {1,-1,0,0};
int n, m;
int u,v;
int ans = 0;
bool allVisit() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(!visit[i][j])
				return true;
		}
	}
	return false;
}
bool check(int u, int v) {
	for(int i=0;i<4;i++) {
		int x = u + dx[i];
		int y = v + dy[i];
		if(x>=0 and x<n and y>=0 and y<m and !visit[x][y])
			return true;
	}
	return false;
}
void select() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(visit[i][j] and check(i,j) and h[i][j] < h[u][v]) {
				u = i;
				v = j;
			}
		}
	}
}
void dfs(int u, int v) {
    for(int i=0;i<4;i++) {
        int x = u + dx[i];
        int y = v + dy[i];
        if(x>=0 and x<n and y>=0 and y<n and !visit[x][y]) {
            if(h[x][y]<=h[u][v]) {
                ans += (h[u][v]-h[x][y]);
                h[x][y] = h[u][v];
                visit[x][y] = 1;
                dfs(x,y);
            } else{
                visit[x][y] = 1;
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    int tt = 0;
    while(t--) {
        tt++;
        ans = 0;
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>h[i][j];
                visit[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++) {
            visit[i][0] = 1;
            visit[i][m-1] = 1;
        }
        for(int i=0;i<m;i++) {
            visit[0][i] = 1;
            visit[n-1][i] = 1;
        }
        h[0][0] = inf;
        while(allVisit()) {
        	u=0;
        	v=0;
        	select();
        	dfs(u,v);
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}