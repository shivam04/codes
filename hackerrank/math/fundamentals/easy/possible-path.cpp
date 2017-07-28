#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd( long long a, long long b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}

int main() {
    int t,flag;
    long long a,b,x,y,m,n;
    cin>>t;
    while(t--){
        flag=0;
        cin>>a>>b>>x>>y;
        if(gcd(x,y)==gcd(a,b))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}