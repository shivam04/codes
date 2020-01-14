#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int i;
	int l=0,r=0;
	char ch = 'a';
	int cnt = 0;
	int maxi = -1;
	for(i=0;i<2;i++){
		ch = 'a'+i;
		l = 0;r=0;
		cnt = 0;
		while(r<n){
			if(s[r]!=ch)
			++cnt;
			while(cnt>k){
				if(s[l]!=ch)
					--cnt;
				++l;
			}
			maxi = max(maxi,r-l+1);
		//	cout<<r-l+1<<" ";
			++r;
		}
	//	cout<<"\n";
	}
	cout<<maxi<<"\n";
	return 0;
}