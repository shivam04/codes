#include<iostream>
using namespace std;
#define mod 1000000007
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long dp[n+1];
        int i;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(i=3;i<=n;i++){
            dp[i] = (dp[i-1]%mod+(i-1)%mod*dp[i-2]%mod)%mod;
        }
        cout<<dp[n]<<"\n";
    }
	return 0;
}