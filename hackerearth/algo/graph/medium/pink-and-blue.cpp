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
vi32 g[100005];
i32 visit[100005];
i32 color[100005];
void dfs(i32 u,i32 c){
    visit[u] = 1;
    color[u] = c;
    //cout<<u<<" "<<c<<"\n";
    i32 i;
    ff0(i,0,g[u].size()){
        i32 v = g[u][i];
        if(!visit[v]){
            dfs(v,1-c);
        }
    }
}
int main() {
	i32 n,m,u,v;
	//wnl("i");
	ri(n);ri(m);
	i32 i;
	string b;
	char a[n+1];
	//rs(b);
	//cin>>b;
	ff1(i,1,n){
	  cin>>a[i];
	}
	ff0(i,0,m){
	    ri(u);ri(v);
	    g[u].pb(v);
	    g[v].pb(u);
	}
	memset(visit,0,sizeof(visit));
	dfs(1,0);
	i32 inva=0;
	ff1(i,1,n){
	    if(a[i]=='B'){
	        if(color[i]==1){
	            inva++;
	        }
	    }
	    else{
	        if(color[i]==0){
	            inva++;
	        }
	    }
	}
		
	i32 ans = min(inva,n-inva);
	wi(ans);
	return 0;
}