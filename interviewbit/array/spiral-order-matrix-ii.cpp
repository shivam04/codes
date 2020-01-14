vector<vector<int> > Solution::generateMatrix(int a) {
    vector<vector<int> > v;
    v.resize(a);
    int r=1,u=0,d=0,l=0;
    int p = a;
    int k = 0;
    int c = 0;
    int m = 0;
    for(int i=0;i<a;i++)
    v[i].resize(a);
    for(int i=1;i<=a*a;i++){
        if(r and c<p){
           v[k][m++] = i; 
           c++;
           if(c==p){
               m = m-1;
               k++;
               p--;
               c = 0;
               r = u = l =0;
               d = 1;
           }
        }
        else if(d and c<p){
            v[k++][m] = i;
            c++;
            if(c==p){
                m--;
                k--;
                r = u = d =0;
               l = 1;
               c = 0;
            }
        }
        else if(l and c<p){
            v[k][m--] = i;
            c++;
            if(c==p){
                m = m+1;
                u = 1;
                r = d = l = 0;
                k--;
                p--;
                c = 0;
            }
        }
        else if(u and c<p){
            v[k--][m] = i;
            c++;
            if(c==p){
                m+=1;
                r = 1;
                u=d=l=0;
                k++;
                c=0;
            }
        }
    }
    return v;
}
