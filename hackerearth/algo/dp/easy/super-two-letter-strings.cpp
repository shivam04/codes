#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long count(string s,int n,int k,int p){
    long long x=0,y=0;
    if(n==0)
    return 1;
    if(k==p){
        y = count(s+'Y',n-1,0,p);
    }else{
        y = count(s+'Y',n-1,k,p);
        x = count(s+'X',n-1,k+1,p);
    }
    return (x+y)%mod;
}
int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long i,n,p;
        cin>>n>>p;
        string s = "Y";
        //long long ans;
        //ans = count(s,n-1,0,p-1)%mod;
        //cout<<ans<<"\n";
        long long k = 0;
        long  long dp[n+1];
        memset(dp,0,sizeof(dp));
        k=0;
        dp[0]=1;
        int j;
        for(i=1;i<=n;i++){
            k =0;
            for(j=i-1;(j>=0);j--){
                
                
                dp[i] +=dp[j];
                dp[i] = (dp[i])%mod;
                k++;
                if(k==p)
                break;
            }
        }
        /*for(i=0;i<2;i++){
            for(int j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
            cout<<"\n";
        }*/
        cout<<dp[n]<<"\n";
    }
    return 0;
}
