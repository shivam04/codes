#include <bits/stdc++.h>
using namespace std;
struct Greedy {
    long long t;
    long long x;
    long long y;
};
int main()
{
    long long n,i;
    long long d;
    cin>>n>>d;
    Greedy a[n+1];
    for(i=0;i<n;i++){
        cin>>a[i].t>>a[i].x>>a[i].y;
    }
    sort(a,a+n, [](Greedy a, Greedy b){ if(a.t==b.t){
            if(a.y==b.y){
                return a.x<b.x;
            }
            return a.y > b.y;
        }
        return a.t < b.t;
    });
    long long sp=0,ar=0,area=0,lt = a[0].t,cost=0;
    for(i=0;i<n;i++){
        ar = sp*(a[i].t-lt);
        area+=ar;
        if(area>=d){
            break;
        }if(a[i].y>sp){
            sp = a[i].y;
            cost+=a[i].x;
        }
        lt = a[i].t;
    }
    cout<<cost<<endl;
    return 0;
}
