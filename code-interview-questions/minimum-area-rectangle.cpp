//O(n^2) O(n)
#include <bits/stdc++.h>
using namespace std;

int minimumAreaRectangle(vector<vector<int>> points) {
  sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2) {
		if(p1[0] != p2[0])
			return p1[0] < p2[0];
		return p1[1] < p2[1];
	});
	int n = points.size();
	map<pair<int,int>,vector<int>> mp;
	for(int i=0;i<n;i++) {
		int k = points[i][0];
		vector<int> y;
		while(i < n and points[i][0] == k) {
			y.push_back(points[i][1]);
			i++;
		}
		i--;
		for(int a=0;a<y.size();a++) {
			for(int b=a+1;b<y.size();b++) {
				mp[{y[a],y[b]}].push_back(k);
			}
		}
	}
	int minArea = 10000000;
	for(auto it: mp) {
		int y1 = it.first.first;
		int y2 = it.first.second;
		int yDiff = (y2-y1);
		vector<int> xs = it.second;
		for(int i=1;i<xs.size();i++) {
			int xDiff = xs[i] - xs[i-1];
			minArea = min(minArea, xDiff*yDiff);
		}
	}
	
  return minArea==10000000?0:minArea;
}



//O(n^2) O(n)
