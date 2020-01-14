#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    int arr[n+1], brr[m+1];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    for(int i=0;i<m;i++) {
	        cin>>brr[i];
	    }
	    int i =0,j=0;
	    for(int i=m-1;i>=0;i--) {
	        int j,last = arr[n-1];
	        for(j=n-2;j>=0 and arr[j] > brr[i];j--) {
	            arr[j+1] = arr[j];
 	        }
 	        if(j != n-2 || last > brr[i]) {
 	            arr[j+1] = brr[i];
 	            brr[i] = last;
 	        }
	    }
	    for(int i=0;i<n;i++) {
	        cout<<arr[i]<<" ";
	    }
	    for(int i=0;i<m;i++) {
	        cout<<brr[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}