#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int k;
    	cin>>k;
    	int n = s.length();
    	int max_win_size = 1;
    	int cs = 0,ce = 0;
    	int mp[26];
    	int pp = 0;
    	memset(mp,0,sizeof(mp));
    	for(int i=0;i<n;i++){
    	    if(mp[s[i]-'a']==0)
    	    pp++;
    	    mp[s[i]-'a']++;
    	}
    	if(pp<k){
    	    cout<<"-1\n";
    	    continue;
    	}
    	memset(mp,0,sizeof(mp));
    	mp[s[0]-'a']++;
    	for(int i=1;i<n;i++){
    	    mp[s[i]-'a']++;
    	    ce++;
    	    while(1){
    	        int p = 0;
    	        for(int j=0;j<26;j++){
    	            if(mp[j]>0)
    	            p++;
    	        }
    	        if(k>=p)
    	        break;
    	        else{
    	            mp[s[cs]-'a']--;
    	            cs++;
    	        }
    	    }
    	    if(ce-cs+1>max_win_size){
    	        max_win_size = ce-cs+1;
    	    }
    	}
    	cout<<max_win_size<<"\n";
    }
	return 0;
}