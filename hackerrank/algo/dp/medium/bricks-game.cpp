#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*long long countsc(long long a[],int p,int n){
    if(n<0)
        return 0;
    if(n==0){
        if(p==0){
            return a[n]; 
        }else{
            return 0;
        }
    }
    else if(n==1){
        if(p==0){
            return a[n]+a[n-1];
        }else{
            return 0;
        }
    }   
    else if(n==2){
        if(p==0){
            return a[n]+a[n-1]+a[n-2];
        }else{
            return 0;
        }
    }
    if(p==0){
        return max(a[n]+countsc(a,1,n-1),max(a[n]+a[n-1]+countsc(a,1,n-2),a[n]+a[n-1]+a[n-2]+countsc(a,1,n-3)));
    }
    if(p==1){
        return min(countsc(a,0,n-1),min(countsc(a,0,n-2),countsc(a,0,n-3)));
    }
    return 0;
}*/

int main() {
    int t,n;
    long long score;
    cin>>t;
    while(t--){
        cin>>n;
        long long a[n+1];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<a[n-1]<<"\n";
            continue;
        }else if(n==2){
            cout<<a[n-1]+a[n-2]<<"\n";
            continue;
        }else if(n==3){
            cout<<a[n-1]+a[n-2]+a[n-3]<<"\n";
            continue;
        }
        //score = countsc(a,0,n-1);
        long long dp[2][n];
        dp[0][n-1]=a[n-1];
        dp[0][n-2]=a[n-1]+a[n-2];
        dp[0][n-3]=a[n-1]+a[n-2]+a[n-3];
        //cout<<"a[n-3]"<<dp[0][n-3]<<"\n";
        dp[1][n-1]=dp[1][n-2]=dp[1][n-3]=0;
        
        for(int i=n-4;i>=0;i--){
            dp[1][i] = min(dp[0][i+1],min(dp[0][i+2],dp[0][i+3]));
            dp[0][i] = max(a[i]+dp[1][i+1],max(a[i]+a[i+1]+dp[1][i+2],a[i]+a[i+1]+a[i+2]+dp[1][i+3]));
        }
        /*for(int i=0;i<n;i++){
            cout<<dp[0][i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<dp[1][i]<<" ";
        }cout<<"\n";*/
        cout<<dp[0][0]<<"\n";
    }
    return 0;
}