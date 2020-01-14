#include <bits/stdc++.h>
using namespace std;

bool comp(pair<long long,long long> p1,pair<long long,long long> p2)
{
	if(p1.first!=p2.first)
		return (p1.first)<(p2.first);
	else
		return (p1.second)<(p2.second);
}

int main() {
	while(true) {
		long long n;
		cin>>n;
		if(n==0)
		break;
		vector<pair<long long,long long>> p;
		map<pair<long long,long long>,long long> mpy;
		vector<pair<long long,long long>> arr;
		long long a,b;
		for(long long i=0;i<n;i++){
			cin>>a>>b;
			p.push_back({a,b});
		}
		sort(p.begin(),p.end());
		for(long long i=0;i<n;i++) {
			if((i+1)<n && p[i].first==p[i+1].first){
				pair<long long,long long> yy = make_pair(p[i].second,p[i+1].second);
				if(mpy[yy]==0)
					arr.push_back(yy);
				mpy[yy]++;
			}
		}
		long long sum = 0;
		
		for(long long i=0;i<arr.size();i++) {
			long long c = mpy[arr[i]];
			if(c % 2 == 1)
				sum+=c*((c-1)/2);
			else
				sum+=(c/2)*(c-1);
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}