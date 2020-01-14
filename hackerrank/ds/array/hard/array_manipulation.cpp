#include <bits/stdc++.h>
using namespace std;
long long A[10000005];
int main() {
     
    int n,m;
    cin>>n>>m;
    int i;
    int a,b;
    long long k;
    for(i=1;i<=n;i++){
        A[i]=0;
    }
    while(m--){
        cin>>a>>b>>k;
        A[a]+=k;
        A[b+1]-=k;
    }
    long long maxi = INT_MIN;
    long long sum = 0;
    for(i=1;i<=n;i++){
        sum+=A[i];
        maxi = max(maxi,sum);
    }
    cout<<maxi<<"\n";
}
