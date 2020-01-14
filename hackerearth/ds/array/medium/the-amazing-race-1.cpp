#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        long long h[n+3];
        stack<long long> s1,s2;
        for(long long i=1;i<=n;i++) {
            cin>>h[i];
        }
        long long ans[n+3];
        memset(ans,0,sizeof(ans));
        s1.push(1);
        for(long long i=2;i<=n;i++) {
            while(!s1.empty() and h[s1.top()] < h[i]) {
                s1.pop();
            }
            ans[i] = ans[i] + (s1.empty() ? i-1 : (i-s1.top()));
            s1.push(i);
        }
        s2.push(n);
        for(long long i=n-1;i>=1;i--) {
            while(!s2.empty() and h[s2.top()] < h[i]) {
                s2.pop();
            }
            ans[i] = ans[i] + (s2.empty() ? n-i : s2.top() - i);
            s2.push(i);
        }
        long long maxi = -1;
        long long maxii = -1;
        for(long long i=1;i<=n;i++) {
            ans[i] = (ans[i]*i)%MOD;
        }
        
        for(long long i=1;i<=n;i++) {
            if(maxi < ans[i]) {
                maxi = ans[i];
                maxii = i;
            }
        }
        cout<<maxii<<"\n";
        
    }
}