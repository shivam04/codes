#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    long long n;
	    cin>>n;
	    long long arr[n];
	    long long sum = 0;
	    long long sumSq = 0;
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	        sum+=arr[i];
	        sumSq+=(arr[i]*arr[i]);
	    }
	    long long ogSum = n*(n+1)/2;
	    long long ogSumSq= n*(n+1)*(2*n+1)/6;
	    long long sumD = ogSum - sum;
	    long long sumSqD = ogSumSq - sumSq;
	    long long sumP = sumSqD/sumD;
	    cout<<(sumP-sumD)/2<<" "<<(sumP+sumD)/2<<"\n";
	}
	return 0;
}