#include<bits/stdc++.h>
using namespace std;
int power(int a, int b) {
    int ans = 1;
    while(b) {
        if(b%2)
            ans = (ans%3*a%3)%3;
        a = (a%3*a%3)%3;
        b/=2;
    }
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    int ans = 0;
	    int p = 0;
	    for(int i=s.length()-1;i>=0;i--) {
	        ans = (ans%3 + power(2,p)%3*(s[i]-'0')%3)%3;
	        p++;
	    }
	    if(ans==0)
	        cout<<"1\n";
	    else
	        cout<<"0\n";
	}
	return 0;
}