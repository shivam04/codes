#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
bool willFit(long arr[], int n, int m, long width) {
	if (arr[0] > width) return false;
	long curW = arr[0];
    int line=1;

	for(int i=1;i<n;i++){
		if (arr[i] > width) return false;
		if ((curW + arr[i]+1) > width) {
			line++;
			curW = arr[i];
		} else {
			curW += arr[i] + 1;
		}
	}    

	return (line <= m);
}
int main() {
	int n,m;
	cin>>n>>m;
	long arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	
	long lo = 0;
	long hi = 1e18;
	long ans = hi;

	while(lo <= hi) {
		long mid = lo + (hi-lo)/2;
		if (willFit(arr, n, m, mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout<<lo<<"\n";
}