#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> v) {
  priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	int n = v.size();
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
	vector<int> dist(n, 100000000);
	dist[start] = 0;
	
	pq.push({0,start});
	while(!pq.empty()) {
		pair <int , int> p = pq.top();  
		pq.pop();
		int x = p.second;
		int wei = p.first;
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = 0; i < v[x].size(); i++){
			int e = v[x][i][0]; int w = v[x][i][1];
			if(dist[x] + w < dist[e]) {
				dist[e] = dist[x] + w;
				pq.push({dist[e], e});
			}
		}
	}
	for(int i=0;i<n;i++) {
		if(dist[i]==100000000)
			dist[i] = -1;
	}
  return dist;
}
