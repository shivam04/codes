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
vi32 g[100005];
i32 start[100005];
i32 finish[100005];
i32 dp[100005];
i32 ro = 0;
void dfs(i32 u,i32 d){
    i32 i;
    dp[u] = d;
    start[u] = ++ro;
    ff0(i,0,g[u].size()){
        i32 v = g[u][i];
        dfs(v,d+1);
    }
    finish[u] = ++ro;
}
i32 main() {
	i32 t;
	ri(t);
	i32 i;
	while(t--){
	    ro=0;
	    ff0(i,0,100005)
	    g[i].clear();
		i32 n;
		ri(n);
		i32 lop,i;
		int root;
		ff1(i,1,n){
		    ri(lop);
		    if(lop==0)
		    root = i;
		    g[lop].push_back(i);
		}
		dfs(root,0);
		i32 q;
		ri(q);
		i32 x,y;
		//for(i=1;i<=n;i++)
		//cout<<start[i]<<" "<<finish[i]<<" "<<dp[i]<<"\n";
		while(q--){
		    ri(x);ri(y);
		    if((start[y]<start[x]) and (finish[x]<finish[y])){
		        cout<<dp[x]-dp[y]-1<<"\n";
		    }else{
		        cout<<"-1\n";
		    }
		}
	}
	return 0;
}
