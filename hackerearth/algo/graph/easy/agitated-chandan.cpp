#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int visited[100001];
int n, tme;
struct node {
	int i,d;
};
typedef struct node node;
vector<node> v[100001];
int bfs (int start) {
	queue<int> q;
	q.push(start);
	for(int i=0;i<=n;i++){
		visited[i]=0;
		dist[i]=0;
	}
	visited[start]=1;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i=0;i<(int)v[temp].size();i++){
			if(visited[v[temp][i].i]==0){
				visited[v[temp][i].i]=1;
				dist[v[temp][i].i]+=dist[temp]+v[temp][i].d;
				q.push(v[temp][i].i);
			}
		}
	}
	return int(max_element(dist+1,dist+n+1)-dist);
}
int main() {
	int u1,v1,d;
	node temp;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			v[i].clear();
		}
		for(int i=1;i<=n-1;i++) {
			scanf("%d%d%d",&u1,&v1,&d);
			temp.i = v1;
			temp.d = d;
			v[u1].push_back(temp);
			temp.i = u1;
			v[v1].push_back(temp);
		}
		int start = bfs(1);
		int ans = bfs(start);
		int finalans = dist[ans];
		int money = 0;
		if (finalans>100)
			money = 100;
		if (finalans>1000)
			money = 1000;
		if (finalans>10000)
			money = 10000;
		printf("%d %d\n",money,finalans);
	}
	return 0;
}