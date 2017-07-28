#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n+1];
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	deque<int> v(k);
//	int maxi = -1;
	for(i=0;i<k;i++){
		while(!v.empty() and arr[i]>=arr[v.back()] )
		v.pop_back();
		v.push_back(i);
	}
	//cout<<maxi<<" ";
	for(i=k;i<n;i++){
		cout<<arr[v.front()]<<" ";
		while(!v.empty() and v.front()<=i-k){
			v.pop_front();
		}
		while(!v.empty() and arr[i]>=arr[v.back()])
		v.pop_back();
		v.push_back(i);
	}
	cout<<arr[v.front()];
	return 0;
}