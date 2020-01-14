#include <bits/stdc++.h>
using namespace std;
//int f[100005];
int main()
{
    int n;
    cin>>n;
    int i;
    int a[n+1];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int f[n+1];
    f[0] = 1;
    for(i=1;i<n;i++){
        if(a[i]>a[i-1]){
            f[i] = f[i-1]+1;
        }
        else{
            f[i]=1;
        }
    }
    int ans = 0;
    for(i=n-2;i>=0;i--){
        if(a[i]>a[i+1] and f[i]<=f[i+1]){
            f[i]=f[i+1]+1;
        }
    }
    for(i=0;i<n;i++)
    ans+=f[i];
    cout<<ans<<"\n";
    return 0;
}
