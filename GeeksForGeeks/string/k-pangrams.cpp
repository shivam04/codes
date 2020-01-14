#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        bool f[26];
        memset(f,false,sizeof(f));
        string s;
        cin>>s;
        int k;
        cin>>k;
        int i;
        int c = 0;
        if(s.length()<26){
            cout<<"0\n";
            continue;
        }
        for(i=0;i<s.length();i++){
            if(f[s[i]-97]==false){
                f[s[i]-97]=true;
                c++;
            }
        }
        if(c+k>=26){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
	return 0;
}