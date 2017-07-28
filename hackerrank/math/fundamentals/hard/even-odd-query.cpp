#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int q,x,y;
    cin>>q;
    while(q--){
        cin>>x>>y;
        if(a[x-1]%2!=0)
            cout<<"Odd\n";
        else if(x==y)
            cout<<"Even\n";
        else if(x!=n&&a[x]==0)
            cout<<"Odd\n";
        else
            cout<<"Even\n";
    }
    return 0;
}