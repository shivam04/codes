#include <bits/stdc++.h>

using namespace std;

int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b);
	//cout<<a<<" "<<b<<"\n";
	map<char,int> mp;
	for(int i=0;i<a.length();i++) {
	    mp[tolower(a[i])]++;
	}
	/*for(auto it = mp.begin(); it!=mp.end(); it++) {
	    cout<<it->first<<" "<<it->second<<"\n";
	}*/
	int flag = 0;
	for(int i=0;i<b.length();i++) {
	    mp[tolower(b[i])]--;
	    if(mp[b[i]] < 0 and b[i]!=' ') {
	       // cout<<b[i]<<" "<<mp[b[i]]<<"\n";
	        flag = 1;
	    }
	}
	if(!flag) {
	    cout<<"YES\n";
	} else {
	    cout<<"NO\n";
	}
}

