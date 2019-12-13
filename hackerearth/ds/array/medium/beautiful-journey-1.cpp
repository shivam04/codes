#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long arr[n+1];
    long long prefix[n+1];
    long long suffix[n+1];
    for(long long i=0;i<n;i++) {
        cin>>arr[i];
    }
    prefix[0] = arr[0];
    for(long long i=1;i<n;i++) {
        prefix[i] = arr[i] + prefix[i-1];
    }
    suffix[n-1] = arr[n-1];
    for(long long i=n-2;i>=0;i--) {
        suffix[i] = arr[i] + suffix[i+1];
    }
    long long maxi = -1;
    for(long long i=0;i<n-1;i++) {
        long long p = prefix[i]*suffix[i+1];
        maxi = max(maxi, p);
    }
    cout<<maxi<<"\n";
}
