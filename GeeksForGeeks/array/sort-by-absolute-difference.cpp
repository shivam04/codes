#include<bits/stdc++.h>
using namespace std;
int x;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n>>x;
	    vector<pair<int,int>>a;
	    int i;
	    int tr;
	    for(i=0;i<n;i++){
	        cin>>tr;
	        a.push_back(make_pair(tr,i));
	    }
	    sort(a.begin(),a.end(),[](pair<int,int> a,pair<int,int> b){
	        if(abs(x-a.first)==abs(x-b.first)){
	            return a.second<b.second;
	        }
	        return abs(x-a.first)<abs(x-b.first);
	    });
	    for(i=0;i<n;i++){
	        cout<<a[i].first<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}