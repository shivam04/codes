#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  scanf("%d",&T);
    while(T--){
        int N,k=0,countK=0;
        string slide;

        scanf("%d",&N);
        cin>>slide;

        slide+=slide;
        //cout<<slide<<"\n";
        for(int i=0;i<N;i++)if(slide[i]=='K')++k;
        //cout<<k<<"\n";

        for(int i=0;i<k;i++){
            if(slide[i]=='K')++countK;
        }
        //cout<<countK<<"\n";
        int  maxK = countK;

        for(int i=k;i<(N+N);i++){
            countK = countK + ((slide[i]=='K')?1:0) - ((slide[i-k]=='K')?1:0); 
            //printf("%d\n",countK);
            maxK = max(maxK,countK);
        }  

       printf("%d\n",(k-maxK));   
    }   
 return 0;
 }