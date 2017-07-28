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
i32 visit[100005];
i32 parent[100005];
i32 child[100005];
i32 ans = 0;
void dfs(int x){
   visit[x]=1;
    i32 cnt = 0;
    //cout<<"x "<<x<<" "<<child[x]<<"\n";
    i32 i;
    ff0(i,0,g[x].size()){
        i32 y = g[x][i];
        if(!visit[y]){
            parent[y]=x;
            cnt++;
            child[x]=cnt;
            dfs(y);
        }
    }
}
int main() {
    initial(visit,0);
    initial(parent,0);
	i32 n,m;
	ri(n);ri(m);
	i32 i;
	i32 a,b;
	ff0(i,0,m){
		ri(a);ri(b);
		g[a].pb(b);
		g[b].pb(a);
		//f[b]=1;
	}
	i32 cnt=0;
	ff1(i,1,n){
	    if(!visit[i]){
	         cnt++,child[i]=cnt;
	        dfs(i);
	    }
	}
	ff1(i,1,n){
	    if(parent[i]!=0 and child[parent[i]]<child[i])
	    ans++;
	}
	cout<<ans<<"\n";
	return 0;
}