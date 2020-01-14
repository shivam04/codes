#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n+1];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    int i =0,j=n-1;
	    int ans = 0;
	    while(i<j) {
	        if(arr[i] == arr[j]) {
	            i++;
	            j--;
	        }
	        else if(arr[i] < arr[j]) {
	            arr[i+1] += arr[i];
	            i++;
	            ans++;
	        } else {
	            arr[j-1]+=arr[j];
	            j--;
	            ans++;
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}