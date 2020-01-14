#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long r,h,i;
        vector<pair<long long,long long> >v;
        for(i=0;i<n;i++){
            cin>>r>>h;
            v.push_back(make_pair(h,r));
        }
        sort(v.begin(),v.end());
        long long j;
        long long maxi = -1;
        long long he[n+1];
        for(i=0;i<n;i++)
        he[i]=v[i].first;
        long long ans = 0;
        for(i=1;i<n;i++){
            he[i] = v[i].first;
            for(j=0;j<i;j++){
                if(v[i].first>v[j].first and v[i].second>v[j].second and he[i]<he[j]+v[i].first){
                    he[i] = he[j]+v[i].first;
                }
            }
        }
        for(i=0;i<n;i++){
            if(maxi<he[i])
            maxi=he[i];
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
