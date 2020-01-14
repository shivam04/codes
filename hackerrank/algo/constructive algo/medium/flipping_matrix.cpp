#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q,n,i,j;
    cin>>q;
    while(q--){
        cin>>n;
        int a[2*n+1][2*n+1];
        for(i=0;i<2*n;i++){
            for(j=0;j<2*n;j++){
                cin>>a[i][j];
            }
        }
        int s = 0;
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               s += max(max(a[i][j],a[i][2*n-j-1]),max(a[2*n-i-1][j],a[2*n-i-1][2*n-j-1]));
           }
       }
        cout<<s<<"\n";
    }
    return 0;
}