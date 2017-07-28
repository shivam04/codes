#include <iostream>
using namespace std;

int main()
{
    long long t,n,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        q--;
        long long ans = n*n - (n%q)*((n+q-1)/q)*((n+q-1)/q) - (q - n%q)*(n/q)*(n/q);
        ans /= 2;
        ans = n*(n-1)/2 - ans;
        cout<<ans<<"\n";
    }
    return 0;
}
