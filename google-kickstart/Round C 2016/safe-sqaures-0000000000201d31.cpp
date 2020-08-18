#include<bits/stdc++.h>
using namespace std;
long long arr[3000][3000];
int main() {
    long long t;
    cin>>t;
    long long tt = 0;
    while(t--) {
        tt++;
        long long ans = 0;
        long long n,m,k;
        cin>>n>>m>>k;
        
        for(long long i=0;i<n;i++) {
            for(long long j=0;j<m;j++) {
                arr[i][j] = 1;
            }
        }
        long long u,v;
        for(long long i=0;i<k;i++) {
            cin>>u>>v;
            arr[u][v] = 0;
        }
        
        for(long long i=1;i<n;i++) {
            for(long long j=1;j<m;j++) {
                if(!arr[i][j])
                    continue;
                arr[i][j] = min( min(arr[i-1][j], arr[i][j-1]), arr[i-1][j-1]) + 1;
            }
        }
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                ans+=arr[i][j];
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}