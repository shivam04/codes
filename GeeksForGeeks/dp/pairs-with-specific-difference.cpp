#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int i,n,k;
	    cin>>n;
	    int a[n],dp[n];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cin>>k;
	    sort(a,a+n);
	    dp[0] = 0;
	    for(i=1;i<n;i++){
	        dp[i] = dp[i-1];
	        if(a[i]-a[i-1]<k){
	            if(i>=2){
	                dp[i] = max(dp[i],a[i]+a[i-1]+dp[i-2]);
	            }else{
	                dp[i] = a[i]+a[i-1];
	            }
	        }
	    }
	    cout<<dp[n-1]<<"\n";
	}
	return 0;
}