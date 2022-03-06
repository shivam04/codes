#include <vector>
using namespace std;
bool traverse(int s, vector<vector<int>> edges, vector<int> &c) {
	c[s] = 1;
	for(int nei: edges[s]) {
		if(c[nei]==1)
			return true;
		if(c[nei]==2)
			continue;
		bool cycle = traverse(nei, edges, c);
		if(cycle)
			return true;
	}
	c[s] = 2;
	return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  int n = edges.size();
	vector<int> c(n,0);
	for(int i=0;i<n;i++) {
		if(c[i]!=0)
			continue;
		bool cycle = traverse(i, edges, c);
		if(cycle)
			return true;
	}
  return false;
}
