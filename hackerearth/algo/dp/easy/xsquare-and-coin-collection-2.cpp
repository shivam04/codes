#include <iostream>
using namespace std;

int main()
{
    long long t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long i,a[n+1];
        long long dp[n+1];
        for(i=1;i<=n;i++){
            cin>>a[i];
            dp[i]=0;
        }
        dp[0]=0;
        //long long maxi = -1;
        long long ans = 0;
        for( i=1;i<=n;i++){
			if(a[i] <= k){
				dp[i] = dp[i-1] + a[i] ;
			}
			ans = max(ans,dp[i]) ;
		}
        cout<<ans<<"\n";
    }
    return 0;
}
