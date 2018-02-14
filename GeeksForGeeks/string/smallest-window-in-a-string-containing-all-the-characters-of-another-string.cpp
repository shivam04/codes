#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    map<int,int> mpa,mpb;
	    int i;
	    for(i=0;i<b.length();i++){
	        mpb[b[i]-97]++;
	    }
	    int cnt = 0;
	    int start =0,sidx=-1,mini=INT_MAX;
	    for(i=0;i<a.length();i++){
	        mpa[a[i]-97]++;
	        if(mpb[a[i]-97]!=0 and mpa[a[i]-97]<=mpb[a[i]-97])
	        cnt++;
	        if(cnt==b.length()){
	            while(mpa[a[start]-97]>mpb[a[start]-97] || mpb[a[start]-97]==0){
	                if(mpa[a[start]-97]>mpb[a[start]-97])
	                mpa[a[start]-97]--;
	                start++;
	            }
	            int win_len = i-start+1;
	            if(win_len < mini){
	                mini = win_len;
	                sidx = start;
	            }
	        }
	    }
	    if(sidx==-1)
	    cout<<-1<<"\n";
	    else{
	        cout<<a.substr(sidx,mini)<<"\n";
	    }
	}
	return 0;
}