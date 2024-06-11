#include <bits/stdc++.h>
using namespace std;

long getGroupSize(long remainingElement) {
	long n = (long)(sqrt(1 + 8*remainingElement) - 1)/2;
	return (n*(n+1))/2;
}
int main(){
	long n;
	cin>>n;
	vector<long> arr(n);
	vector<long> prefixSum(n+1, 0);
	for(long i=0;i<n;i++) {
		cin>>arr[i];
		prefixSum[i+1] = (arr[i] + prefixSum[i]);
	}

	long maxi = arr[n-1];
	for(long i=0;i<n;i++) {
		long rE = n-i;
		long grpSize = getGroupSize(rE);
		maxi = max(maxi, prefixSum[i+grpSize] - prefixSum[i]);
	}
	cout<<maxi<<"\n";
}
