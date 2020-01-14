#include <bits/stdc++.h>
using namespace std;

int al[1001][1001];
char ans[1001][1001];
int mv[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
char cc;
char dfs(int x,int y, int h, int w) {
	//if(ans[x][y])
		//return ans[x][y];
	int mx=-1,my=-1,mini=20000;
	
	for(int i=0;i<4;i++) {
		int nx = x + mv[i][0];
		int ny = y + mv[i][1];
		if(nx < 0 or ny < 0 or nx >= h or ny >= w or al[x][y] <= al[nx][ny])
			continue;
		if(mini > al[nx][ny]) {
			mx = nx;
			my = ny;
			mini = al[nx][ny];
		}
	}
	
	if(mx < 0) {
		if(ans[x][y]) return ans[x][y];
		return ans[x][y] = cc++;
	}
	
	return ans[x][y] = dfs(mx,my,h,w);
}

int main() {
	fstream fout,fin;
    fin.open("B-large-practice.txt",ios::in);
    fout.open("B-large-practice-output.txt",ios::out);
	int t;
	fin>>t;
	for(int c=1;c<=t;c++) {
		int h,w;
		fin>>h>>w;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				fin>>al[i][j];
			}
		}
		cc = 'a';
		memset(ans,0,sizeof(ans));
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if(ans[i][j])
				continue;
				dfs(i,j,h,w);
			}
		}
		
		
		fout<<"Case #"<<c<<":\n";
		
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				fout<<ans[i][j]<<" ";
			}
			fout<<"\n";
		}
	}
	return 0;
}