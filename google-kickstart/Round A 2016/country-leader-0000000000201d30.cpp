#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int tt = 0;
    while(t--) {
        tt++;
        int n;
        cin>>n;
        string ans="";
        int maxi = 0;
        string s;
        getline(cin,s);
        for(int i=0;i<n;i++) {
            getline(cin,s);
            map<char,int> mp;
            for(int j=0;j<s.length();j++) {
                if(s[j]==' ')
                    continue;
                mp[s[j]] = 1;
            }
            int p = mp.size();
            if(p>maxi) {
                ans = s;
                maxi = p;
            }
            if(p==maxi) {
                if(ans>s)
                ans=s;
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}