#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> >v,u;
vector<long long> l;
void modify(){
    long long i,sz,a,b;
    u.push_back(v[0]);
    sz = v.size();
    long long y = 0;
    for(i=1;i<sz;i++){
        a = v[i].first;
        b = v[i].second;
        if(a>u[y].second){
            y++;
            u.push_back(make_pair(a,b));
        }else{
            u[y].second = max(u[y].second,b);
        }
    }
}
long long bs(long long n, long long k){
    long long mid,calc;
    long long low=0,high=n;
    while(low<=high){
        mid = (low+high)/2;
        if(l[mid]<k and (mid==n || l[mid+1]>=k) ){
            if(mid==n)
            return -1;
            else{
                calc = k - l[mid];
                return u[mid].first+calc-1;
            }
            
        }else if(k>l[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
}
int main()
{
    long long t;
    cin>>t;
    while(t--){
        u.clear();
        v.clear();
        l.clear();
        long long n,q,a,b;
        cin>>n>>q;
        long long i;
        
        for(i=0;i<n;i++){
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        modify();
        long long sz = u.size();
        
        l.push_back(0);
        long long calc;
        for(i=0;i<sz;i++){
            calc=u[i].second-u[i].first+1+l[i];
			l.push_back(calc);
        }
        long long k;
        while(q--){
            cin>>k;
            calc = bs(sz,k);
            cout<<calc<<"\n";
        }
    }
    return 0;
}
