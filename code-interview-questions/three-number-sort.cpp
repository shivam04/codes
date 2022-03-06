#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  unordered_map<int,int> mp;
	int k = 0;
	for(int a: array) {
		mp[a]++;
	}
	int i = 0;
	for(auto o: order) {
		int n = o;
		int cnt = mp[o];
		for(int c=0; c<cnt;c++) {
			array[i++] = n;
		}
	}
  return array;
}