#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    int visit[26];
	    memset(visit,-1,sizeof(visit));
	    visit[a[0]-97] = 0;
	    int cur_len = 1,max_len=1,p_i=-1;
	    for(int i=1;i<a.size();i++){
	        p_i = visit[a[i]-97];
	        if(p_i==-1 || i-cur_len>p_i){
	            cur_len++;
	        }else{
	            max_len = max(max_len,cur_len);
	            cur_len = i-p_i;
	        }
	        visit[a[i]-97] = i;
	    }
	    cout<<max(cur_len,max_len)<<"\n";
	}
	return 0;
}