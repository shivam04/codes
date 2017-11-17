int visited[100001];
void bfs (int start) {
	queue<int> q;
	q.push(start);
	int i;
	ff1(int i,0,n){
		visited[i]=0;
	}
	visited[start]=1;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		ff0(i,0,g[temp].size()){
			int u = g[temp][i];
			if(visited[u]==0){
				visited[u]=1;
				q.push(u);
			}
		}
	}
}