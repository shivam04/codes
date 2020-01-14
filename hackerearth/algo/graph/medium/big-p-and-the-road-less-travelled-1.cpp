#include <bits/stdc++.h>
using namespace std;
#define ri(x) scanf("%d",&x);
#define rl(x) scanf("%ld",&x);
#define rf(x) scanf("%f",&x);
#define rd(x) scanf("%lf",&x);
#define wi(x) printf("%d",x);
#define wl(x) printf("%ld",x);
#define wf(x) printf("%f",x);
#define wd(x) printf("%lf",x);
#define wnl(d) printf(d);
#define ff0(i,a,b) for(i=a;i<b;i++)
#define ff1(i,a,b) for(i=a;i<=b;i++)
#define fr0(i,a,b) for(i=a;i>b;i--)
#define fr1(i,a,b) for(i=a;i>=b;i--)
#define i32 int
#define i64 long long 
#define f32 float 
#define f64 double 
#define vi32 vector<int> 
#define vl64 vector<long long> 
#define vf32 vector<float> 
#define vd64 vector<double> 
#define vc32 vector<char> 
#define vs64 vector<string> 
#define si32 set<int> 
#define sl64 set<long long> 
#define sf32 set<float> 
#define sd64 set<double> 
#define sc32 set<char> 
#define ss64 set<string> 
#define pb(i) push_back(i)
#define mp(i,j) make_pair(i,j)
#define vpi32 vector<pair<int ,int> > 
#define vpl64 vector<pair<long long, long long> > 
#define vps64 vector<pair<string ,string> > 
#define f first
#define s second
#define initial(i,j) memset(i,j,sizeof(i))
vi32 g[10005];
i32 visit[10005];
i32 dp[10005];
i32 dfs (i32 start,i32 finish) {
   if(start==finish)
   return 1;
   if(visit[start])
   return dp[start];
   visit[start]=1;
   i32 i;
   i32 ans = 0;
   ff0(i,0,g[start].size()){
       i32 u = g[start][i];
       ans+=dfs(u,finish);
       dp[start]=ans;
   }
   return ans;
}
int main() {
	i32 n;
	ri(n);
	i32 i;
	i32 a,b;
	i32 path = 0;
	initial(visit,0);
	initial(dp,0);
	while(1){
	    ri(a);ri(b);
	    
	    if(a==0 and b==0)
	    break;
	    path++;
	    g[a].push_back(b);
	}
	wi(dfs(1,n));
	return 0;
}