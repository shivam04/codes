//O(n^2) O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> getSlope(vector<int> p1, vector<int> p2) {
	int x1 = p1[0];
	int y1 = p1[1];
	int x2 = p2[0];
	int y2 = p2[1];
	vector<int> slope = {0,1};
	if(x1 != x2) {
		int xDiff = x2-x1;
		int yDiff = y2-y1;
		int gcd = __gcd(abs(xDiff), abs(yDiff));
		xDiff = xDiff/gcd;
		yDiff = yDiff/gcd;
		if(xDiff < 0) {
			xDiff *= -1;
			yDiff *= -1;
		}
		slope = {xDiff, yDiff};
	}
	return slope;
}
int lineThroughPoints(vector<vector<int>> points) {
	int ans = 1;
  sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2) {
		if(p1[0] != p2[0])
			return p1[0] < p2[0];
		return p1[1] < p2[1];
	});
	int n = points.size();
	for(int i=0;i<n;i++) {
		map<pair<int,int>, int> slopes;
		for(int j=i+1;j<n;j++) {
			vector<int> slope = getSlope(points[i], points[j]);
			int den = slope[0];
			int num = slope[1];
			if(slopes.find({num,den})==slopes.end())
				slopes[{num,den}]=1;
			slopes[{num,den}]++;
		}
		int cans = 0;
		for(auto it: slopes) {
			if(it.second > cans)
				cans = it.second;
		}
		ans = max(ans, cans);
	}
  return ans;
}


//O(n^2) O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> getSlope(vector<int> p1, vector<int> p2) {
	int x1 = p1[0];
	int y1 = p1[1];
	int x2 = p2[0];
	int y2 = p2[1];
	vector<int> slope = {1,0};
	if(x1!=x2) {
		int xDiff = x1-x2;
		int yDiff = y1-y2;
		int gcd = __gcd(abs(xDiff), abs(yDiff));
		xDiff /= gcd;
		yDiff /= gcd;
		if(xDiff < 0) {
			xDiff *= -1;
			yDiff *= -1;
		}
		slope = {yDiff, xDiff};
	}
	return slope;
}

int lineThroughPoints(vector<vector<int>> points) {
  int ans = 1;
	int n = points.size();
	for(int i=0;i<n;i++) {
		auto p1 = points[i];
		unordered_map<string, int> slopes;
		for(int j=i+1;j<n;j++) {
			auto p2 = points[j];
			auto slope = getSlope(p1,p2);
			string key = to_string(slope[0]) + ":" + to_string(slope[1]);
			if(slopes.find(key)==slopes.end())
				slopes[key] = 1;
			slopes[key]+=1;
		}
		int cans = 0;
		for(auto it: slopes) {
			if(it.second > cans)
				cans = it.second;
		}
		ans = max(ans, cans);
	}
  return ans;
}
