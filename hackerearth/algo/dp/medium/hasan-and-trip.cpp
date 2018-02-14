#include<bits/stdc++.h>
using namespace std;
double x[3005],y[3005],f[3005];
double dp[3005];
int kd[3005];
double solve(int t,int n){
    //cout<<"FDFD "<<t<<" "<<kd[t]<<"\n";
    if(t==n-1)
    return f[t];
    if(kd[t]!=-1){
        //cout<<"SDA "<<dp[t]<<"\n";
        return dp[t];
    }
    double ans;
    double mini;
    int fl = 0;
    for(int i=t+1;i<n;i++){
        ans = solve(i,n);
        if(!fl){
            fl=1;
            mini = (double)(ans+f[t]-sqrt((x[t]-x[i])*(x[t]-x[i])+(y[t]-y[i])*(y[t]-y[i])));
        }else{
            mini = max((double)(ans+f[t]-sqrt((x[t]-x[i])*(x[t]-x[i])+(y[t]-y[i])*(y[t]-y[i]))),(double)mini);
        }
        //cout<<"DFGFDGDFDFDFGF "<<t<<" "<<i<<" "<<mini<<"\n";
    }
    if(kd[t]!=-1)
    dp[t] = max(dp[t],mini);
    else{
        kd[t] = 1;
        dp[t] = mini;
    }
    //cout<<t<<" "<<kd[t]<<" "<<dp[t]<<"\n";
    return mini;
}
int main(){
    int n;
    cin>>n;
    int i;
    //memset(dp,-1,sizeof(dp));
    for(i=0;i<n;i++){
        kd[i]=-1;
        cin>>x[i]>>y[i]>>f[i];
    }
    double ans = solve(0,n);
    cout<<fixed;
    cout<<setprecision(6)<<ans<<"\n";
}