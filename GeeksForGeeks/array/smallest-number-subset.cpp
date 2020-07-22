#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    int res = 1;
	    for(int i=0;i<n && arr[i] <= res;i++) {
	        res +=  arr[i];
	    }
	    cout<<res<<"\n";
	}
	return 0;
}