#include <bits/stdc++.h>
using namespace std;
long long soln(char *s,long long n){
	
	if(n==0 || n==1)
		return 1;
	long long count = 0;
	if(s[n-1]>'0'){
		//cout<<"dssdf"<<"\n";
		//cout<<s<<" "<<n<<"\n";
		count = soln(s,n-1);
		//cout<<s<<" "<<n<<"\n";
	}if (s[n-2] < '2' || (s[n-2] == '2' && s[n-1] < '7') ){
		//cout<<"sfsf"<<"\n";
		count+=soln(s,n-2);
		//cout<<s<<" "<<n<<"\n";
	}
	return count;
}
int main() {
	char s[5005];
	cin>>s;
	while(s[0]!='0'){
		//cout<<s.size()<<"\n";
		long long n = strlen(s);
	//cout<<soln(s,n)<<"\n";
		
		long long dp[n+2];
		for(int i=0;i<=n;i++){
			dp[i]=0;
		}
		dp[0]=1;
		dp[1]=1;
		for(long long i=2;i<=n;i++){
			
			
			if(s[i-2]=='1' || (s[i-2]=='2' and s[i-1]<'7')){
				if(s[i-1]=='0')
				dp[i]=dp[i-2];
				else
				dp[i]=dp[i-1]+dp[i-2];
			}else{
				dp[i]=dp[i-1];		
				}
		}
		cout<<dp[n]<<"\n";
		cin>>s;
	}
	return 0;
}