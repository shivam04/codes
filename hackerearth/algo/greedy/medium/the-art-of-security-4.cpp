#include <bits/stdc++.h>
using namespace std;
int a[12],ans=0,b[2];
void solve(int num,int n){
    if(num==n){
        if(b[0]<=b[1])
        ans++;
        return;
    }else if(b[0]+a[num]<=b[1]){
        b[0]+=a[num];
        solve(num+1,n);
        b[0]-=a[num];
    }
        
        b[1]+=a[num];
        solve(num+1,n);
        b[1]-=a[num];
}
int main()
{
    int n;
    cin>>n;
    int i;
    int sum=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    do{
        b[0]=0;
        b[1]=0;
        solve(0,n);
    }while(next_permutation(a,a+n));
    cout<<ans<<" "<<sum<<"\n";
    if(ans<=sum)
    cout<<"Got no way out!\n";
    else
    cout<<"We will win!\n";
    
}
