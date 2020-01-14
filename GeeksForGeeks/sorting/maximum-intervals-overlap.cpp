#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,int> > a;
	    vector<pair<int,int> > d;
	    int i;
	    int y;
	    for(i=0;i<n;i++){
	        cin>>y;
	        a.push_back({y,i});
	    }
	    
	    for(i=0;i<n;i++){
	        cin>>y;
	        d.push_back({y,i});
	    }
	    sort(a.begin(),a.end());
	    sort(d.begin(),d.end());
	    int result = 0;
	    int rx = -1;
	    int ry = -1;
	    i=0;
	    int j=0;
	    int r;
	    int mm = 0;
	    while(i<n and j<n){
	        if(a[i].first<=d[j].first){
	            mm++;
	            if(result<=mm){
	                result = mm;
	                rx = a[i].first;
	               // ry = a[j].first;
	            }
	            i++;
	        }else{
	            mm--;
	            j++;
	        }
	    }
	    cout<<result<<" "<<rx<<"\n";
	}
	return 0;
}