//6pts
#include<bits/stdc++.h>
using namespace std;
int modPow(int a, int b, int m) {
    int ans = 1;
    a = a%m;
    while(b) {
        if(b & 1)
            ans = (ans*a)%m;
        a = (a*a)%m;
        b/=2;
    }
    return ans%m;
}
int main() {
    int t;
    cin>>t;
    int tt = 0;
    while(t--) {
        tt++;
        int a,b,n,k;
        cin>>a>>b>>n>>k;
        int ans = 0;
        int mod = 1000000007;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i!=j){
                    if((modPow(i,a, k) + modPow(j,b, k))%k ==0 )
                        ans = (ans+1)%mod;
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}

//15pts
