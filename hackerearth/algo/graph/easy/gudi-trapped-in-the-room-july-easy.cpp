#include <bits/stdc++.h>
using namespace std;
//int visit[1000006];
int main()
{
    int t,i;
    cin>>t;
    while(t--){
       // memset(visit,0,sizeof(visit));
        string st;
        cin>>st;
        int a,h;
        cin>>a>>h;
        set<string> s;
        stack<string> rs;
        s.insert(st);
        rs.push(st);
        //visit[stoi(st)] = 1;
        int mini = 1000000007;
        while(!rs.empty()){
            string p = rs.top();
            rs.pop();
            //cout<<p<<"\n";
            int n = p.size();
            string hy = p;
            for(i=0;i<n;i++){
                hy[(i+h)%n] = p[i];
            }
            
            if(s.find(hy)==s.end()){
                s.insert(hy);
                rs.push(hy);
            }
            for(i=1;i<n;i+=2){
                int k = ((p[i]-48)+a)%10;
                p[i] = char(48+k);
            }
            if(s.find(p)==s.end()){
                s.insert(p);
                rs.push(p);
            }
            
        }
        cout<<*(s.begin())<<"\n";
    }
    return 0;
}
