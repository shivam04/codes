#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
map<int,int> f;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    int a,i;
	    v.clear();
	    f.clear();
	    //memset(f,0,sizeof(f));
	    for(i=0;i<n;i++){
	        cin>>a;
	        f[a]++;
	    }
	    map<int,int>::iterator it;
	    for(it=f.begin();it!=f.end();++it){
	        if(it->second>0){
	            v.push_back({it->second,it->first});
	        }
	    }
	    int l = v.size();
	    sort(v.begin(),v.end());
	    cin>>m;
	    /*for(i=0;i<v.size();i++){
	        cout<<v[i].second<<" "<<v[i].first<<"\n";
	    }*/
	    for(i=0;i<v.size() and m>0;i++){
	        if(v[i].first<=m){
	            m-=v[i].first;
	            l--;
	        }else{
	            break;
	        }
	    }
	    cout<<l<<"\n";
	}
	return 0;
}