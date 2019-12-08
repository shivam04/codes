#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        unordered_set<int> s; 
        int j = 0;
        long long ans = 0;
        for(int i=0;i<n;i++) {
            while(j<n and s.find(arr[j]) == s.end()) {
                s.insert(arr[j]);
                j++;
            }
            long long len = j-i;
            ans += (len)*(len+1)/2;
            s.erase(arr[i]); 
        }
        cout<<ans<<"\n";
    }
}

