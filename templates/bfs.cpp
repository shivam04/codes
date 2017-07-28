i32 visited[100001];
void bfs (i32 start) {
	queue<i32> q;
	q.push(start);
	i32 i;
	ff1(i32 i,0,n){
		visited[i]=0;
	}
	visited[start]=1;
	while(!q.empty()){
		i32 temp = q.front();
		q.pop();
		ff0(i,0,g[temp].size()){
			i32 u = g[temp][i];
			if(visited[u]==0){
				visited[u]=1;
				q.push(u);
			}
		}
	}
}