#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long count( int S[], int m, int n )
{
    long long i, j, x, y;

    long long table[n+1][m];
    
    for (i=0; i<m; i++)
        table[0][i] = 1;
  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {

            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            y = (j >= 1)? table[i][j-1]: 0;

            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
int main() {

    int n,m;
    cin>>n>>m;
    if(n==0){
        cout<<"0";
    }else if(m==0){
        cout<<"1";
    }else{
        int c[m+1];
        for(int i=0;i<m;i++){
            cin>>c[i];
        }
        cout<<count(c, m, n);
    }
    
    return 0;
}
