#include <bits/stdc++.h>
using namespace std;
#define MOD 100000
typedef long long int int64;
 
int main()
{
    long long s,k,n;
    cin>>s>>k;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    cin>>a[i];
     int ans[100005];
    memset(ans,-1,sizeof(ans));
   
    queue <long> q;
    q.push(s);
    ans[s]=0;
    while(!q.empty()){
        int64 val = q.front();
        q.pop();
        if(val==k)
        break;
        for(int i=0;i<n;i++){
            int64 to = a[i];
            to = to*val;
            to%=100000;
            if(ans[to]==-1){
                ans[to] = ans[val]+1;
                q.push(to);
            }
        }
    }
    cout<<ans[k]<<"\n";
    return 0;
}