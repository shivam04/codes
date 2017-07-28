#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int i,a[n+1],b[m+1];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<m;i++){
        cin>>b[i];
    }
    long long k,l;
    long long s1=0,s2=0;
    sort(a,a+n);
    sort(b,b+m);
    for(i=0;i<n;i++){
        k = lower_bound(b,b+m,a[i])-b;
        l = upper_bound(b,b+m,a[i])-b;
        //cout<<k<<" "<<l<<"\n";
        s1 += (k*(m-l));
    }
    for(i=0;i<m;i++){
        k = lower_bound(a,a+n,b[i])-a;
        l = upper_bound(a,a+n,b[i])-a;
        //cout<<k<<" "<<l<<"\n";
        s2 += (k*(n-l));
    }
    if(s1==s2)
    cout<<"Tie\n";
    else if(s1>s2)
    cout<<"Monk "<<s1-s2<<"\n";
    else
    cout<<"!Monk "<<s2-s1<<"\n";
    return 0;
}
