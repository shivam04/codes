#include <iostream>
using namespace std;

int main() {
	int arr[] = {50, 40, 70, 60, 90};
	int index[] = {3,  0,  4,  1,  2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i=0;
	while(i<n){
		
		while(index[i]!=i){
			int p =arr[i];
			arr[i]=arr[index[i]];
			arr[index[i]] = p;
			int q = index[i];
			index[i] = index[index[i]];
			index[q] = q;
			i++;
		}
		i++;
	}
	for(i=0;i<n;i++)
	cout<<index[i]<<" ";
	return 0;
}