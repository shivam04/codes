#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int l = s.length();
	    int i;
	    for(i=0;i<l/2;i++){
	        swap(s[i],s[l-i-1]);
	    }
	    cout<<s<<"\n";
	}
	return 0;
}