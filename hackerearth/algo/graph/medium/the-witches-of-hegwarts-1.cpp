#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t,n;
   cin>>t;
   vector<int> v;
        set<int> s;
   while(t--){
        cin>>n;
        v.clear();
        s.clear();
        queue<int> q;
        q.push(n);
        int p = 0;
        
        //dist[n] = 0;
        int flag = 0;
        int i,m;
        m=1;
        i=0;
        if(n==1)flag=1;
        
        v.push_back(n);
        while(!flag){
            p++;
          for(i;i<m;i++){
              int a=-1,b=-1,c=-1;
              if(v[i]%3==0)a=v[i]/3;
              if(v[i]%2==0)b=v[i]/2;
              c = v[i]-1;
              if(a!=1 and s.find(a)== s.end() ){
                  s.insert(a);
                  v.push_back(a);
              }
              if(b!=1 and s.find(b)== s.end() ){
                  s.insert(b);
                  v.push_back(b);
              }
              if(s.find(c)== s.end() ){
                  s.insert(c);
                  v.push_back(c);
              }
              if(a==1 || b==1 || c==1)
              flag=1;
          }
          i=m;
          m=v.size();
          
        }
        cout<<p<<"\n";
   }
    return 0;
}
