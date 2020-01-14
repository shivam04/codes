#include <bits/stdc++.h>
using namespace std;
long long dp[20][2][20];
long long var;
vector<long long> digit;
void getdigit(long long x){
    while(x){
        digit.push_back(x%10);
        x/=10;
    }
}
long long ispalin(long long index,long long len){
      long long id = 0;
      long long d = var;
      long long oo[20];
      for( ; d ; id ++, d/=10) oo[id] =  d%10;
      for(long long i= id-1; i> index; i-- ){
            d= 10*d + oo[i];
      }
      for(long long i = index + ((len%2)? 2 : 1); i < len ;i ++) {
            d = d*10+oo[i];
      }
      if(d <= var) return 1;
      return 0;
}
 
long long getans(long long idx,long long tight,long long len){
    if(idx==(len)/2-1){
    	if(tight && len) return ispalin(idx,len);
    	return 1;
    }
    if(dp[idx][tight][len]!=-1 and !tight)  
    return dp[idx][tight][len];
    long long p = (tight)?digit[idx]:9;
    long long i;
    long long ans = 0;
    for(i=0;i<=p;i++){
        ans+=getans(idx-1,tight&&(i==p),i?(len==0?idx+1:len):len);
    }
   if(!tight)
   dp[idx][tight][len] = ans;
   return ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long a,b;
    long long t;
    cin>>t;
    long long p =t;
    while(t--){
       
	digit.clear();
        cin>>a>>b;
     memset(dp,-1,sizeof(dp));
        long long i = min(a,b);
        long long j = max(a,b);
        a = i;
        b = j;
        var = a-1;
        getdigit(a-1);
        if(digit.size()==0)
        digit.push_back(0);
        long long ans1 = getans(digit.size()-1,1,0);
        memset(dp, -1, sizeof dp);
        digit.clear();
        var = b;
        getdigit(b);
        long long ans2 = getans(digit.size()-1,1,0);
        cout<<"Case "<<p-t<<": "<<ans2-ans1<<"\n";
    }
    return 0;
}