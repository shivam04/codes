#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i;
    int a[n+1];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int f;
    int dp[n+1];
    if(a[0]==0)
    {
        dp[1]=1;
    }else{
        dp[1]=0;
    }
    int cf3 = 0;
    f = a[0];
    for(i=1;i<n;i++){
        if(a[i]==0){
            dp[i+1]=dp[i]+1;
            f=0;
        }
        if(a[i]==1){
            if(f==2 || f==3 || f==0){
                dp[i+1] = dp[i];
                f = 1;
            }else{
                dp[i+1]=dp[i]+1;
                f=0;
            }
        }
        if(a[i]==2){
            if(f==1 || f==3 || f==0){
                
                dp[i+1] = dp[i];
                f = 2;
            }else{
                dp[i+1]=dp[i]+1;
                f=0;
            }
        }
        if(a[i]==3){
            if(f==1){
                dp[i+1]=dp[i];
                f = 2;
            }else if(f==2){
                dp[i+1]=dp[i];
                f = 1;
            }else{
               
                dp[i+1]=dp[i];
                f=3;
            }
        }
        
    }
    cout<<dp[n]<<"\n";
    return 0;
}
