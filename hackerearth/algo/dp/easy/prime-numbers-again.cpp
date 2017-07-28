#include <bits/stdc++.h>
using namespace std;
int prime[10005];
vector<int> p;
void seive(){
    int i,j;
    for(i=2;i<=10002;i++){
        prime[i]=1;
    }
    for(i=2;i*i<=10002;i++){
        if(prime[i]==1){
            for(j=i*2;j<=10002;j+=i){
                prime[j]=0;
            }
        }
        
    }
    for(i=2;i<=10004;i++){
        if(prime[i])
        p.push_back(i);
    }
    prime[4]=1;
    prime[27]=1;
    prime[3125]=1;
}
int main()
{
    seive();
    p.push_back(4);
    p.push_back(27);
    p.push_back(3125);
   // cout<<p.size()<<"\n";
    sort(p.begin(),p.end());
    int dp[100004];
    dp[2]=1;
    dp[3]=1;
    //cout<<prime[5]<<"\n";
    int i,j;
    for(i=4;i<=10002;i++){
        dp[i]= 1000000007;
        if(prime[i]==1){
            dp[i]=1;
            continue;
        }
        for(j=0;j<p.size();j++){
            if(i-p[j]<2)
            break;
            else
            dp[i] = min(dp[i],dp[i-p[j]]+1);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
        
    }
    return 0;
}
