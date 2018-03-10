#include<bits/stdc++.h>
using namespace std;
int cmp(pair<int,int> x,pair<int,int> y){
    if(x.second==y.second){
        return x.first<y.first;
    }
    return x.second>y.second;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    map<int,int> mp;
	    int i;
	    int a;
	    for(i=0;i<n;i++){
	        cin>>a;
	        mp[a]++;
	    }
	    vector<pair<int,int>> v;
	    map<int,int>::iterator it;
	    for(it=mp.begin();it!=mp.end();++it){
	        v.push_back({it->first,it->second});
	    }
	    sort(v.begin(),v.end(),cmp);
	    for(i=0;i<v.size();i++){
	        for(int j=0;j<v[i].second;j++)
	        cout<<v[i].first<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}