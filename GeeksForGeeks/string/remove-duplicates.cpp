#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	string s;
	getline(cin,s);
	while(t--){
	    unordered_map<int,int> mp;
	    getline (cin,s);
	    for(int i=0;i<s.length();i++){
    	    if(mp[s[i]]==0){
    	           cout<<s[i];
    	           mp[s[i]]=1;
    	    }
	    }
	    cout<<"\n";
	}
	return 0;
}