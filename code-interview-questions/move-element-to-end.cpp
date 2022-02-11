#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int cnt = 0;
	for(int n: array) {
		cnt += (n==toMove);
	}
	int j = 0;
	for(int i=0;i<array.size();i++) {
		if(array[i] != toMove) {
			swap(array[i], array[j]);
			j++;
		}
	}
	for(int i=j;i<array.size();i++) {
		array[i] = toMove;
	}
  return array;
}
