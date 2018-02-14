#include <bits/stdc++.h>
using namespace std;
map<long long ,pair<long long,long long> > mp;
pair<long long,long long> ans(long long m){
	if(m==0){
		return make_pair(0,0);
	}
	if(mp.find(m)!=mp.end()){
		//cout<<mp[m].first<<"\n";
		return mp[m];
	}
	//cout<<"M "<<m<<" "<<(mp.find(m)==mp.end())<<"\n";
	long long cr = cbrt(m);
	//cout<<cr<<"\n";
	if(cr==1)
	return make_pair(m,m);
	pair<long long,long long> p = ans(m-cr*cr*cr);
	p.first+=1;
	p.second+=(cr*cr*cr);
	pair<long long,long long> q = ans(cr*cr*cr-1);
	if(q.first>p.first){
	        p=q;
	}
	else if(q.first==p.first && q.second>p.second){
	        p=q;
	}
	return mp[m] = p;
}
int main() {
	long long m;
	cin>>m;
	pair<long long,long long> a = ans(m);
	cout<<a.first<<" "<<a.second;
	return 0;
}