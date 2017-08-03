#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX 1001
int lookup[MAX][MAX];
long long countSeqUtil(long long n, long long dif)
{
    // We can't cover diference of more
    // than n with 2n bits
    if (abs(dif) > n)
        return 0;
 
    // n == 1, i.e., 2 bit long sequences
    if (n == 1 && dif == 0)
        return 2;
    if (n == 1 && abs(dif) == 1)
        return 1;
 
    // Check if this subbproblem is already solved
    // n is added to dif to make sure index becomes
    // positive
    if (lookup[n][n+dif] != -1)
        return lookup[n][n+dif]%mod;
 
    long long res = // First bit is 0 & last bit is 1
              (countSeqUtil(n-1, dif+1)%mod)+
 
              // First and last bits are same
              (2*countSeqUtil(n-1, dif)%mod) +
 
              // First bit is 1 & last bit is 0
              (countSeqUtil(n-1, dif-1)%mod)%mod;
 
    // Store result in lookup table and return the result
    return lookup[n][n+dif] = res%mod;
}
 
// A Wrapper over countSeqUtil().  It mainly initializes lookup
// table, then calls countSeqUtil()
long long countSeq(long long n)
{
    // Initialize all entries of lookup table as not filled
    memset(lookup, -1, sizeof(lookup));
 
    // call countSeqUtil()
    return countSeqUtil(n, 0);
}
 
int main() {
	long long t;
	cin>>t;
	long long n;
	while(t--){
	    cin>>n;
	    cout<<countSeq(n)<<endl;
	}
	return 0;
}