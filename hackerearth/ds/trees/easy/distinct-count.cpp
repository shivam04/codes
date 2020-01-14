#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int t,n,x,i,l;
   cin>>t;
   while(t--){
   	cin>>n>>x;
   	int a[n+1];
   	for(i=0;i<n;i++){
   		cin>>a[i];	
   	}
   	sort(a,a+n);
   	l=0;
   	for(i=0;i<n;i++){
   		if(a[i]==a[i-1])
   		continue;
   		l++;
   	}
   	if(l<x)
   	cout<<"Bad husband\n";
   	if(l==x)
   	cout<<"Perfect husband\n";
   	if(l>x)
   	cout<<"Lame husband\n";
   }
    return 0;
}
