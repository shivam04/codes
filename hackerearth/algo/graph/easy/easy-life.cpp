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
#define vi64 vector<long long> 
#define vf32 vector<float> 
#define vd64 vector<double> 
#define vc32 vector<char> 
#define vs64 vector<string> 
#define si32 set<int> 
#define si64 set<long long> 
#define sf32 set<float> 
#define sd64 set<double> 
#define sc32 set<char> 
#define ss64 set<string> 
#define pb(i) push_back(i)
#define mp(i,j) make_pair(i,j)
#define vpi32 vector<pair<int ,int> > 
#define vpi64 vector<pair<long long, long long> > 
#define vps64 vector<pair<string ,string> > 
#define f first
#define s second
#define initial(i,j) memset(i,j,sizeof(i))
vi64 g[100005];
i64 visit[100005];
i64 rt = 0;
int  dfs(int x){
    visit[x] = 1;
    i64 cnt=1;
    i64 i,y;
    ff0(i,0,g[x].size()){
        y = g[x][i];
        rt++;
        if(!visit[y]){
            cnt+=dfs(y);
        }
    }
    return cnt;
}
int main() {
    initial(visit,0);
	i64 n,m;
	ri(n);ri(m);
	i64 i;
	ff0(i,0,m){
		i32 a,b;
		ri(a);ri(b);
		g[a].pb(b);
		g[b].pb(a);
	}
	//i64 cnt = 0;
	i64 maxi = -1;
	i64 f1 = 0;
	ff1(i,1,n){
	    if(!visit[i]){
	        //cnt++,edge[i]=cnt;
	        rt = 0;
	        i64 k = dfs(i);
	        cout<<k<<" "<<rt<<"\n";
	        rt/=2;
	        if(rt>k){
	            cout << ">1" << endl;
                return 0;
	        }else if(rt==k){
	           f1 = 1; 
	        }else{
	            maxi = max(maxi,k);
	        }
	    }
	}
	if(f1){
	    cout<<"1/1\n";
	}else{
	    wi(maxi-1);wnl("/");wi(maxi);
	}
	
	return 0;
}