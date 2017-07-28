/tree-counting-3#include <bits/stdc++.h>
using namespace std;
long long A[505],k,parent[505];
long long ad[505][505]={0};

int main()
{
    long long n;
    cin>>n>>k;
    long long i;
    for(i=1;i<=n;i++){
        cin>>A[i];
    }
  
    long long p;
    for(i=2;i<=n;i++){
        cin>>p;
        parent[i]=p;
    }
    long long j,m;
    for(i=2;i<=n;i++){
        m = i;
        while(m!=1){
            m = parent[m];
            ad[m][i] = 1;
        }
    }
    long long count = 0;
    long long l;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(l=1;l<=n;l++){
                if(i==j or j==l or l==i)
                continue;
                if(ad[i][j] and ad[i][l] and A[i]+A[j]+A[l]>=k)
                count++;
            }
        }   
    }
    cout<<count/2<<"\n";
    return 0;
}
