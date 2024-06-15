#include <bits/stdc++.h>
using namespace std;

class Graph {
	public:
		vector<vector<int>> graph;
		vector<int> disc, low, visited, parent, AP;
		vector<pair<int,int>> bridges;
		int V;
		int times = 0;

		Graph(int V) {
			this->V = V;
			this->graph.resize(V);
			this->disc.resize(V);
			this->low.resize(V);
			this->visited.resize(V, 0);
			this->parent.resize(V, -1);
			this->AP.resize(V, 0);
		}

		void addEdge(int x, int y) {
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		void findAPB(int v) {
			visited[v] = 1;
			disc[v] = low[v] = ++times;
			int child = 0;
			for (auto u: graph[v]) {
				if (visited[u] == false) {
					child = child + 1;
					parent[u] = v;
					findAPB(u);
					low[v] = min(low[v], low[u]);
					if (low[u] > disc[v]) {
						bridges.push_back({v,u});
					}
					if (parent[v] == -1 and child > 1) {
						AP[v] = 1;
					}
					if (parent[v] != -1 and low[u] >= disc[v]) {
						AP[v] = 1;
					}
				} else if (parent[v] != u) {
					low[v] = min(low[v], disc[u]);
				}
			}
		}
};

int main() {
	int n,m;
	cin>>n>>m;
	Graph g(n);
	int x,y;
	for(int i=0;i<m;i++) {
		cin>>x>>y;
		g.addEdge(x,y);
	}
	g.findAPB(0);
	int sum = 0;
	for(int i=0;i<n;i++) {
		sum+=g.AP[i];
	}
	cout<<sum<<"\n";
	for(int i=0;i<n;i++) {
		if (g.AP[i] == 1) {
			cout<<i<<" ";
		}
	}
	sort(g.bridges.begin(), g.bridges.end());
	cout<<"\n"<<g.bridges.size()<<"\n";
	for (auto edge: g.bridges) {
		cout<<edge.first<<" "<<edge.second<<"\n";
	}
}