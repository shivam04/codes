#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n+1];
	    int i;
	    long long sum = 0;
	    map<int,int> mp;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    int k;
	    cin>>k;
	    for(i=0;i<n;i++){
	        mp[a[i]%k]++;
	    }
	    if(sum%k==0){
	        for(i=0;i<n;i++){
	           int rem = a[i]%k;
	           if(2*rem==k){
	               if(mp[rem]%2!=0){
	                   break;
	               }
	           }
	           else if(rem==0){
	               if(mp[rem]%2!=0)
	               break;
	           }
	           else if(mp[rem]!=mp[k-rem]){
	               break;
	           }
	        }
	        if(i==n)
	        cout<<"True\n";
	        else
	        cout<<"False\n";
	    }else{
	        cout<<"False\n";
	    }
	}
	return 0;
}