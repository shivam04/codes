#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,p,m;
	cin>>t;
	while(t--){
		cin>>p>>m;
		int arr[p+1];
		int i,k = 0;
		long long sum = 0;
		//deque<int> v;
		for(i=0;i<p;i++){
			cin>>arr[i];
		}
		int o = 0;
		int mp = -1 , minm = 1000000009;
		for(i=0;i<p;i++){
			if(sum+arr[i]<=m){
				sum+=arr[i];
				k++;
			}else{
				sum+=arr[i];
				while(sum>m){
					sum-=arr[o];
					o++;
					k--;
				}
			}
			if(mp<k){
				mp=k;
				minm = sum;
			}else if(mp==k){
				if(minm>sum){
					minm = sum;
				}
			}
		}
		cout<<minm<<" "<<mp<<"\n";
	}
	return 0;
}