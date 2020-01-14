#include <iostream>
using namespace std;

int main()
{
    long long n,q;
    cin>>n>>q;
    long long i;
    long long a[n+1],b[n+1],prea[n+1],preb[n+1];
    prea[0]=0;
    preb[0]=0;
    for(i=1;i<=n;i++){
        cin>>a[i];
        prea[i] = prea[i-1]+a[i];
    }
    for(i=1;i<=n;i++){
        cin>>b[i];
        preb[i] = preb[i-1]+a[i];
    }
    long long t,l,r;
    while(q--){
        cin>>t>>l>>r;
        long long ans;
        if(t==1){
            ans = 0;
            int k = 0;
            for(i=l;i<=r;i++){
                if(!k){
                    ans+=a[i];
                    k=1-k;
                }else{
                    ans+=b[i];
                    k=1-k;
                }
            }
        }else{
            ans = 0;
            int k = 1;
            for(i=l;i<=r;i++){
                if(!k){
                    ans+=a[i];
                    k=1-k;
                }else{
                    ans+=b[i];
                    k=1-k;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
