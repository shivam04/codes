#include<bits/stdc++.h>
using namespace std;
int comp(string x,string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx)>0?1:0;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<string> arr;
	    int i;
	    string h;
	    for(i=0;i<n;i++){
	        cin>>h;
	        arr.push_back(h);
	    }
	    sort(arr.begin(),arr.end(),comp);
	    for(i=0;i<n;i++)
	    cout<<arr[i];
	    cout<<"\n";
	}
	return 0;
}