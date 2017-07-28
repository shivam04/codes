#include <bits/stdc++.h>
using namespace std;
long long count(long long a[], long long n, long long sum,long long tot){
    if(n>=tot)
    return sum;
    return max(count(a,n+2,sum+a[n],tot),count(a,n+1,sum,tot));
}
int main()
{
    long long t,n,i;
    cin>>t;
    int h=0;
    while(t--){
        cin>>n;
        long long a[n+1];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        long long dp[n+1];
        long long j;
       // long long ans = count(a,0,0,n);
       dp[0]=0;
        dp[1]=a[0];
       // cout<<dp[1]<<" ";
        for(i=2;i<=n;i++){
            dp[i] = max(dp[i-2]+a[i-1],dp[i-1]);
           // cout<<dp[i]<<" ";
        }
        //cout<<"\n";
        cout<<"Case "<<++h<<": "<<dp[n]<<"\n";
    }
    return 0;
}
