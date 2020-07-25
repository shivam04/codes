#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n+1];
    int s[n+1];
    for(int i=0;i<n;i++) {
        cin>>a[i]; 
    }
    s[0] = a[0]==0 ? -1 : 1;
    int lastIndex = -1;
    for(int i=1;i<n;i++) {
        s[i] = s[i-1] + (a[i]==0 ? -1 : 1);
    }
    int cnt = 0;
    for(int i=0;i<n;i++) {
        
        if(s[i]==0)
        cnt++;
    }
    cout<<(cnt==0 ? -1 : cnt)<<"\n";
}