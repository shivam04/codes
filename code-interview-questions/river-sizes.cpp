#include <vector>
using namespace std;
vector<vector<int>> mv{{0,-1}, {1,0}, {-1,0}, {0,1}};
bool isValid(int i, int j, int w, int h) {
	return i>=0 and i<w and j>=0 and j<h;
}
int traverseNode(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &visited,
									int w, int h) {
	queue<pair<int,int>> q;
	q.push({i,j});
	visited[i][j] = 1;
	int cc = 1;
	while(!q.empty()) {
		pair<int,int> c = q.front();
		q.pop();
		int x = c.first;
		int y = c.second;
		for(vector<int> m: mv) {
			int xx = x+m[0];
			int yy = y+m[1];
			if(isValid(xx,yy,w,h) and !visited[xx][yy] and matrix[xx][yy]) {
				q.push({xx,yy});
				cc++;
				visited[xx][yy] = 1;
			}
		}
	}
	return cc;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  int w = matrix.size();
	int h = matrix[0].size();
	vector<int> sizes;
	vector<vector<int>> visited(w, vector<int>(h, false));
	for(int i=0;i<w;i++) {
		for(int j=0;j<h;j++) {
			if(visited[i][j] or matrix[i][j]==0)
				continue;
			sizes.push_back(traverseNode(i, j, matrix, visited, w, h));
		}
	}
  return sizes;
}
