#include <vector>
using namespace std;
vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0},{-1,0}};
queue<pair<int,int>> getAllPOsitive(vector<vector<int>> matrix) {
	queue<pair<int,int>> q;
	int w = matrix.size();
	int h = matrix[0].size();
	for(int i=0;i<w;i++) {
		for(int j=0;j<h;j++) {
			if(matrix[i][j]>0) {
				q.push({i,j});
			}
		}
	}
	return q;
}

bool isValid(int i, int j, int w, int h) {
	return (i>=0 and i<w and j>=0 and j<h);
}

bool containsNegative(vector<vector<int>> matrix) {
	for(auto row: matrix) {
		for(auto val: row) {
			if(val < 0)
				return true;
		}
	}
	return false;
}

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
  queue<pair<int,int>> q = getAllPOsitive(matrix);
	int w = matrix.size();
	int h = matrix[0].size();
	if(q.size()==0)
		return -1;
	if(q.size()==w*h)
		return 0;
	int pass = 0;
	int ans = 0;
	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			auto curr = q.front();
			q.pop();
			int r = curr.first;
			int c = curr.second;
			for(auto dir: dirs) {
				int x = r + dir.first;
				int y = c + dir.second;
				if(isValid(x,y,w,h) and matrix[x][y] < 0) {
					matrix[x][y] *= -1;
					q.push({x,y});
				}
			}
		}
		ans++;
	}
  return !containsNegative(matrix) ? ans-1: -1;
}
