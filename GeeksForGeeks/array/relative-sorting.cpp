#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int N;
int cmp(int x,int y){
    if(mp[x]==N and mp[y]==N)
    return x<y;
    if(mp[x]==N)
    return 0;
    if(mp[y]==N)
    return 1;
    return mp[x]<mp[y];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    N = n+1;
	    int a1[n+1];
	    int i;
	    int a;
	    mp.clear();
	    for(i=0;i<n;i++){
	        cin>>a1[i];
	        mp[a1[i]]=n+1;
	    }
	    for(i=0;i<m;i++){
	        cin>>a;
	        mp[a]=(i);
	    }
	    sort(a1,a1+n,cmp);
	    for(i=0;i<n;i++){
	        cout<<a1[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}