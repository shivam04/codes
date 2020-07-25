#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int c = 0;
    for(int i=0;i<n;i++) {
        if(a[i] != b[i])
            c++;
    }
    int w = n - c;
    if(w == k) {
        cout<<n<<"\n";
    } else if(w>=k) {
        cout<<k+c<<"\n";
    } else {
        cout<<n-k+w<<"\n";
    }
    return 0;

}