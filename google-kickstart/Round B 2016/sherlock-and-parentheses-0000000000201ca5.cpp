#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int tt = 0;
    while(t--) {
        tt++;
        long l,r;
        long ans = 0;
        cin>>l>>r;
        long p = min(l,r);
        ans = ((p+1)*p)/2;
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}