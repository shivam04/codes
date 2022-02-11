#include <vector>
using namespace std;

int maximizeExpression(vector<int> array) {
  int n = array.size();
	if(n<4)
		return 0;
	int table1[n], table2[n], table3[n], table4[n];
	for(int i=0;i<n;i++) {
		table1[i] = table2[i] = table3[i] = table4[i] = INT_MIN;
	}
	table1[0] = array[0];
	for(int i=1;i<n;i++) {
		table1[i] = max(table1[i-1], array[i]);
	}
	for(int i=1;i<n;i++) {
		table2[i] = max(table2[i-1], table1[i-1]-array[i]);
	}
	for(int i=2;i<n;i++) {
		table3[i] = max(table3[i-1], table2[i-1]+array[i]);
	}
	for(int i=3;i<n;i++) {
		table4[i] = max(table4[i-1], table3[i-1]-array[i]);
	}
  return table4[n-1];
}
