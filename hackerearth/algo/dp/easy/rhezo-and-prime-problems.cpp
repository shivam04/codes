#include <bits/stdc++.h>
using namespace std;
#define MAX 5005
vector<long long> v;
int prime[5005];
void Sieve()
{
    int n = MAX;
    //int prime[n+1];
    
	for(int i=0;i<=n;i++)
	prime[i]=1;
	prime[0]=prime[1]=0;
	
	for(int i=2;i*i<=n;i++) {
		if(prime[i]==1)
			for(int j=i*i;j<=n;j+=i)
				prime[j]=0;
	}
	
	for(int i=2;i<=n;i++)
		if(prime[i]==1)
			v.push_back(i);
}

int main()
{
    Sieve();
    long long n;
    cin>>n;
    //cout<<n<<"\n";
    long long a[n+1],i;
    for(i=1;i<=n;i++){
        cin>>a[i];
       // if(a[i]>100000)
        //cout<<a[i]<<"\n";
    }
    long long pre[n+1];
    pre[0] = 0;
    for(i=1;i<=n;i++){
        pre[i] = pre[i-1]+a[i];
        //cout<<pre[i]<<" ";
    }
    //cout<<pre[1550]<<"\n";
    //long long k = binarySearch(0, primes.size()-1, n);
    if(prime[n]==1){
        cout<<pre[n]<<"\n";
        return 0;
    }
    //cout<<k<<"\n";
    long long mp = -1;
    long long dp[n+1];
    dp[0]=dp[1]=0;
    for(i=2;i<=n;i++){
        if(prime[i]==1){
            dp[i] = pre[i];
            mp = i;
        }
        else{
            dp[i] = dp[i-1];
            for(long long j=0;j<v.size()&&v[j]<=mp;j++){
                dp[i]=max(dp[i],pre[i]-pre[ i-v[j] ]+dp[ i-v[j]-1 ]);
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
