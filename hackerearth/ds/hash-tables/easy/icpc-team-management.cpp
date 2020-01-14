#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    int t,i,len,flag;
    cin>>t;
    int n,k;
    char a[110];
    int c[110];
    while(t--){
    	flag=0;
    	for(i=0;i<110;i++)
    	c[i]=0;
    	cin>>n>>k;
    	for(i=0;i<n;i++){
    		cin>>a;
    		len = strlen(a);
    		c[len]++;
    	}
    	for(i=0;i<110;i++)
    	{
    		if(c[i]%k!=0)
    		{
    			//cout<<c[i]<<"\n";
    			flag=1;
    			break;
    		}
    	}
    	if(flag==0)
    	cout<<"Possible\n";
    	else
    	cout<<"Not possible\n";
    }
    return 0;
}