#include<bits/stdc++.h>9
using namespace std;

int main() {
    int t;
    cin>>t;
    int tt = 0;
    while(t--) {
        tt++;
        double n,m;
        cin>>n>>m;
        double ans = (n-m)/(n+m);
        printf("Case #%d: %.8lf\n", tt, ans);
    }
}