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
	    int sumr[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        sum[i]=a[i];
	        sumr[i] = a[i];
	    }
	    //int maxi = a[0];
	    for(i=1;i<n;i++){
	        for(j=0;j<i;j++){
	            if(a[i]>a[j] and sum[i]<sum[j]+a[i]){
	                sum[i] = sum[j]+a[i];
	            }
	            
	        }
	    }
	    for(i=n-2;i>=0;i--){
	        for(j=n-1;j>i;j--){
	            if(a[i]>a[j] and sumr[i]<sumr[j]+a[i]){
	                sumr[i] = sumr[j]+a[i];
	            }
	            
	        }
	    }
	    int maxi = sum[0] + sumr[0]-a[0];
	    for(i=1;i<n;i++)
	    maxi = max(maxi,sum[i]+sumr[i]-a[i]);
	    cout<<maxi<<"\n";
	}
	return 0;
}