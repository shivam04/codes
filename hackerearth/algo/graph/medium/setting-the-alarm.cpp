#include <bits/stdc++.h>
using namespace std;
int visit[13][62][3];
int dist[13][62][3];
queue< pair< pair<int, int>, int> > q;
void hplus(int h,int m, int p){
    h++;
    if(h==12){
        p=1-p;
    }
    if(h>12){
        h=1;
    }
    if(!visit[h][m][p]){
        q.push(make_pair(make_pair(h,m),p));
    }
}
void hminus(int h,int m, int p){
    h--;
    if(h==11){
        p=1-p;
    }
    if(h<1){
        h=12;
    }
    if(!visit[h][m][p]){
        q.push(make_pair(make_pair(h,m),p));
    }
}
void mplus(int h,int m,int p){
    m++;
    if(m<=59){
        if(!visit[h][m][p]){
            q.push(make_pair(make_pair(h,m),p));
        }
    }else{
        m=0;
        hplus(h,m,p);
    }
}
void mminus(int h,int m,int p){
    m--;
    if(m>=0){
        if(!visit[h][m][p]){
            q.push(make_pair(make_pair(h,m),p));
        }
    }else{
        m=59;
        hminus(h,m,p);
    }
}
void hashap(int h,int m,int p){
    p=1-p;
    if(!visit[h][m][p]){
        q.push(make_pair(make_pair(h,m),p));
    }
}
int main()
{
     vector<string> v;
    set<string> se;
    int t;
    cin>>t;
    while(t--){
        int h1,m1,h2,m2;
        char s1[5],s2[5];
        scanf("%d:%d %s %d:%d %s",&h1,&m1,s1,&h2,&m2,s2);
        int ap1=0,ap2=0;
        if(strcmp(s1,"pm")==0){
            ap1=1;
        }
        if(strcmp(s2,"pm")==0){
            ap2=1;
        }
        //q.clear();
        q.push(make_pair(make_pair(h1,m1),ap1));
        memset(visit, 0, sizeof(visit));
        int ans = 0;
        while(!q.empty()){
            int k = q.size();
            
            for(int i=0;i<k;i++){
                pair<pair<int,int>,int> x = q.front();
                q.pop();
                int h = x.first.first,m=x.first.second,ap=x.second;
                if(visit[h][m][ap])
                continue;
                visit[h][m][ap] = 1;
                dist[h][m][ap]=ans;
                hplus(h,m,ap);
                hminus(h,m,ap);
                mplus(h,m,ap);
                mminus(h,m,ap);
                hashap(h,m,ap);
            }
            ans++;
        }
        cout<<dist[h2][m2][ap2]<<"\n";
    }
    return 0;
}