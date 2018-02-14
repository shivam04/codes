#include<bits/stdc++.h>
using namespace std;
#define maxii 1234567890123456789LL
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i,j,e;
        int m[n+1];
        vector<long long> A[n+1];
        for(i=0;i<n;i++){
            cin>>m[i];
            for(j=0;j<m[i];j++){
                cin>>e;
                A[i].push_back(e);
            }
        }
        
        vector<long long> S[i];
        for(i=0;i<n;i++)
        S[i].resize(m[i],0);
        for(i=1;i<n;i++){
            long long max1 = -maxii;
            long long max2 = -maxii;
            for(j=0;j<m[i-1];j++){
                max1 = max(max1,S[i-1][(j+1)%m[i-1]]-1LL*i*A[i-1][j]);
                max2 = max(max2,S[i-1][(j+1)%m[i-1]]+1LL*i*A[i-1][j]);
            }
            for(j=0;j<m[i];j++){
                S[i][j] = max(S[i][j],max(max1+1LL*i*A[i][j],max2-1LL*i*A[i][j]));
            }
        }
        long long ans;
        for(i=0;i<m[n-1];i++){
            ans = max(ans,S[n-1][i]);
        }
        cout<<ans<<"\n";
    }
}