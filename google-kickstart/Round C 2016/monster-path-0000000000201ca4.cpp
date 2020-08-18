#include<bits/stdc++.h>
using namespace std;
double arr[22][22];
double pp[22][22];
int r,c,rs,cs,s;
double p,q;
double ans = 0.0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
double max(double a, double b) {
    return (a>b) ? a : b;
}
void anss(int u,int v, int s, double prob) {
	double p = pp[u][v];
    if(s==0) {
        ans = max(ans, prob);
        return;
    }
    prob+=p;
    pp[u][v] = p*(1.0-arr[u][v]);
    for(int i=0;i<4;i++) {
        int x = u + dx[i];
        int y = v + dy[i];
        if(x>=0 and x<r and y>=0 and y<c) {
            anss(x,y,s-1,prob);
        }
    }
    pp[u][v] = p;
}
int main() {
    long long t;
    cin>>t;
    long long tt = 0;
    while(t--) {
        tt++;
        cin>>r>>c>>rs>>cs>>s;
        cin>>p>>q;
        char ch;
        memset(pp, 0.0 ,sizeof(pp));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>ch;
                if(ch=='.')
                    arr[i][j] = pp[i][j] = q;
                else
                    arr[i][j] = pp[i][j] = p;
            }
        }
        ans = 0.0;
        if(rs-1>=0 and rs-1<r and cs>=0 and cs<c)
        	anss(rs-1,cs,s, 0.0);
        if(rs+1>=0 and rs+1<r and cs>=0 and cs<c)
        	anss(rs+1,cs,s,0.0);
        if(rs>=0 and rs<r and cs-1>=0 and cs-1<c)
        	anss(rs,cs-1,s,0.0);
        if(rs>=0 and rs<r and cs+1>=0 and cs+1<c)
        	anss(rs,cs+1,s,0.0);
        cout<<setiosflags(ios::fixed) << setprecision(7);
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}