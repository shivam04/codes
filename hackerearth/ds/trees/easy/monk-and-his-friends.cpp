#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int i;
        long long arr[n+m+1];
        set<long long> s;
        for(i=0;i<n+m;i++){
            cin>>arr[i];
        }
        for(i=0;i<n;i++){
            s.insert(arr[i]);
        }
        for(i=n;i<n+m;i++){
            if(s.find(arr[i])!=s.end()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
            s.insert(arr[i]);
        }
        
        
    }
    return 0;
}
