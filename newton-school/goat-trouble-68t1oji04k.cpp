#include <bits/stdc++.h>
using namespace std;
int x,y,hx1,hy1,hx2,hy2;
double S(int a,int b,int c,int d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
 
}
int main()
{
    scanf("%d%d%d%d%d%d",&x,&y,&hx1,&hy1,&hx2,&hy2);
    double ans=0,tmp1,tmp2;
    if(hx1<=x&&x<=hx2){
        ans=min(abs(hy1-y),abs(hy2-y));
    }else if(hy1<=y&&y<=hy2){
        ans=min(abs(hx1-x),abs(hx2-x));
    }else{
        tmp1=min(S(x,y,hx1,hy1),S(x,y,hx2,hy2));
        tmp2=min(S(x,y,hx1,hy2),S(x,y,hx2,hy1));
        ans=min(tmp1,tmp2);
    }
    printf("%.3lf\n",ans+0.00000001);
    //cout << "Hello world!" << endl;
    return 0;

}