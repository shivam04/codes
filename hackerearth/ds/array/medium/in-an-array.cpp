#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int main() {
    int n,x,y,k;
    cin>>n>>k>>x>>y;
    int a;
    map<int,long> mp;
    for(int i=0;i<n;i++) {
        cin>>a;
        mp[a]++;
    }
    long ans = 0;
    for(int i=1;i<maxn;i++) {
        for(int j=i;j<maxn;j++) {
            int p = (i+j)%k;
            int q = (i*j)%k;
            if(p==x and q==y) {
                if(i==j) {
                    ans += (mp[i]-1)*mp[i]/2;
                } else {
                    ans += (mp[i]*mp[j]);
                }
            }
        }
    }
    cout<<ans<<"\n";
    
}
