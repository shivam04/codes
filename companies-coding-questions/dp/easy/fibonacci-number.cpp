#include<bits/stdc++.h>

using namespace std;

int main()  {
    int a;
    cin>>a;
    vector<int> f(a+1, 0);
    f[1] = 1;
    f[2] = 1;
    for(int i=2;i<=a;i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cout<<f[a]<<"\n";
    return 0;
}