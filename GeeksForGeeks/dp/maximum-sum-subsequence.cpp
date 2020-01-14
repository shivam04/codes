#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i,j;
	    cin>>n;
	    int a[n+1];
	    int sum[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        sum[i]=a[i];
	    }
	    int maxi = a[0];
	    for(i=1;i<n;i++){
	        for(j=0;j<i;j++){
	            if(a[i]>a[j] and sum[i]<sum[j]+a[i]){
	                sum[i] = sum[j]+a[i];
	            }
	            
	        }
	        maxi=max(maxi,sum[i]);
	    }
	    cout<<maxi<<"\n";
	}
	return 0;
}