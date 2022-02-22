#include <vector>
using namespace std;

vector<int> sortKSortedArray(vector<int> array, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
  for(int i=0;i<min(k+1, (int)array.size());i++) {
		pq.push(array[i]);
	}
	int s = 0;
	for(int i=k+1;i<array.size();i++) {
		int minE = pq.top();
		pq.pop();
		array[s++] = minE;
		pq.push(array[i]);
	}
	while(!pq.empty()) {
		int minE = pq.top();
		pq.pop();
		array[s++] = minE;
	}
  return array;
}
