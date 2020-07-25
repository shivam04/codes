#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n+1], b[n+1];
    int ans = -1;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
    }
    for (int i=n;i>=0;i--)  {
        int cnt = 0;
        for (int j=1;j<=n;j++) {
            if(a[j] <= i and b[j] >= i)
            cnt++;
        }
        if(cnt == i) {
            ans = cnt;
            break;
        }

    }
    cout<<ans<<"\n";
}