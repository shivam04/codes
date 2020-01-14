#include <bits/stdc++.h>
using namespace std;
#define ri(x) scanf("%d",&x);
#define rl(x) scanf("%lld",&x);
#define rf(x) scanf("%f",&x);
#define rd(x) scanf("%lf",&x);
#define wi(x) printf("%d",x);
#define wl(x) printf("%lld",x);
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
i32 visit[100005];
i64 a[100005];
i64 dfs(i32 u){
    stack<i32> s;
    s.push(u);
    i64 rec = a[u];
   // wl(rec);wnl(" ");
    i32 i;
    visit[u] = 1;
    while(!s.empty()){
        i32 p = s.top();
        s.pop();
        ff0(i,0,g[p].size()){
            i32 v = g[p][i];
            if(visit[v]==0){
                s.push(v);
                visit[v]=1;
                rec+=a[v];
               // wl(rec);wnl(" ");
            }
        }
    }
   // wnl("\n");
    //wl(rec);wnl("\n");
    return rec;
}
int main() {
	i32 t;
	ri(t);
	i32 i;
	while(t--){
	    ff1(i,0,100004)
	    g[i].clear();
	    initial(visit,0);
		i32 n,m;
		ri(n);ri(m);
		i32 u,v;
		ff0(i,0,m){
		    ri(u);ri(v);
		    g[u].pb(v);
		    g[v].pb(u);
		}
		
		ff1(i,1,n){
		    rl(a[i]);
		}
		i64 maxi = -1;
		i64 k ;
		ff1(i,1,n){
		    if(!visit[i]){
		        k = dfs(i);
		    }
		    maxi = max(maxi,k);
		}
		//wnl("ans ");
		wl(maxi);wnl("\n");
		
	}
	return 0;
}