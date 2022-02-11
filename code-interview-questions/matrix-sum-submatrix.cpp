#include <vector>
using namespace std;

int maximumSumSubmatrix(vector<vector<int>> matrix, int size) {
  int h = matrix.size();
	int w = matrix[0].size();
	vector<vector<int>> tempV;
	for(int i=0;i<h;i++) {
		int s = 0;
		vector<int> v;
		for(int j=0;j<size;j++) {
			s += matrix[i][j];
		}
		v.push_back(s);
		for(int j=size;j<w;j++) {
			s += (matrix[i][j] - matrix[i][j-size]);
			v.push_back(s);
		}
		tempV.push_back(v);
	}
	int newC = w-size+1;
	int newR = h-size+1;
	int ans = INT_MIN;
	int k = 0;
	for(int j=0;j<newC;j++) {
		int s = 0;
		vector<int> v;
		for(int i=0;i<size;i++) {
			s += tempV[i][j];
		}
		ans = max(ans, s);
		for(int i=size;i<h;i++) {
			s += (tempV[i][j] - tempV[i-size][j]);
			ans = max(ans, s);
		}
		
	}
  return ans;
}
