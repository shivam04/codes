#include <vector>

using namespace std;
bool isOutOfBounds(int r, int c, int h, int w) {
	return r<0 or r>h or c<0 or c>w;
}
vector<int> zigzagTraverse(vector<vector<int>> array) {
  int h = array.size()-1;
	int w = array[0].size()-1;
	vector<int> res = {};
	int r = 0;
	int c = 0;
	bool isDown = true;
	while(!isOutOfBounds(r,c,h,w)) {
		res.push_back(array[r][c]);
		if(isDown) {
			if(c==0 or r==h) {
				isDown = false;
				if(r==h) {
					c++; 
				} else {
					r++;
				}
			} else {
				r++;
				c--;
			}
		} else {
			if(r==0 or c==w) {
				isDown = true;
				if(c==w) {
					r++; 
				} else {
					c++;
				}
			} else {
				r--;
				c++;
			}
		}
	}
  return res;
}
