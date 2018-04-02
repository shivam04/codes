int visited[100001];
void bfs (int start) {
	queue<int> q;
	q.push(start);
	int i;
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	visited[start]=1;
	while(!q.empty()){
		int temp = q.front();
		cout<<temp<<" ";
		q.pop();
		for(int i=0;i<g[temp].size();i++){
			int u = g[temp][i];
			if(visited[u]==0){
				visited[u]=1;
				q.push(u);
			}
		}
	}
}