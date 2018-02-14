#include<bits/stdc++.h>
using namespace std;
int dp[501][501][11][11];
string s,p;
int ans(int n,int m,int k1,int k2){
    if(k1==-1 or k2==-1)
    return -1;
    if(m==0 or n==0)
    return 0;
    if(dp[n][m][k1][k2]!=-1)
    return dp[n][m][k1][k2];
    if(s[n-1]==p[m-1]){
        dp[n][m][k1][k2] = ans(n-1,m-1,k1,k2)+1;
    }else{
        dp[n][m][k1][k2] =max(max(ans(n,m-1,k1,k2),ans(n-1,m,k1,k2)),max(ans(n-1,m-1,k1,k2-1)+1,ans(n-1,m-1,k1-1,k2)+1));
    }
    return dp[n][m][k1][k2];
}
int main(){
    cin>>s>>p;
    int k1,k2;
    cin>>k1>>k2;
    memset(dp,-1,sizeof(dp));
    cout<<ans(s.length(),p.length(),k1,k2)<<"\n";
}
