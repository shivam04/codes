#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int mod_pow(long long int w,long long int p,long long int m){
    long long int ans = 1;
    long long int a= w;
    while(p){
        if(p%2!=0)
            ans=(ans*a)%m;
        p/=2;
        a=(a*a)%m;
    }
    return ans;
}

int main() {
    long long int t,a,m,p;
    long long int k;
    cin>>t;
    while(t--){
        cin>>a>>m;
        if(a==0){
            cout<<"YES\n";
            continue;
        }
        p=(m-1)/2;
        k = mod_pow(a,p,m);
        if(k==1)
            cout<<"YES"<<"\n";
        else
            cout<<"NO\n";
    }
    return 0;
}