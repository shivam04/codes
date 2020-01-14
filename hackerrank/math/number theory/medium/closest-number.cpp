#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,a,b,x,ans,zz;
    cin>>t;
    while(t--){
        cin>>a>>b>>x;
        ans = pow(a,b);
        if(ans==0)
            cout<<"0\n";
        else{
              zz=ans%x;
            //cout<<zz<<"\n";
            if(zz>x/2)
                cout<<ans-zz+x<<"\n";
            else
                cout<<ans-zz<<"\n";
        }
    }
    return 0;
}