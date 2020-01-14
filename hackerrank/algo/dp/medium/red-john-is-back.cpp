#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void binomialCoeff(int n, int k,long long C[41][11])
{
    //int C[n+1][k+1];
    int i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    //return C[n][k];
}
void seive(int n ,int p[]){
	int prime[n+1];
	prime[0]=prime[1]=0;
	int i,j;
	for(i=0;i<n;i++){
		prime[i]=1;
		p[i]=0;
	}
	for(i=2;i*i<=n;i++){
		if(prime[i]){
			for(j=2*i;j<=n;j=j+i){
				prime[j]=0;
			}
		}
	}
	int count = 0;
	//int p;
	for (int q=2; q<=n; q++){
		if(prime[q]){
		count++;
			p[q]=count;
		}else{
			p[q]=count;
		}
	}
}
int main() {
	int np[220000];
	seive(217300,np);
    long long C[41][11];
       binomialCoeff(40,10,C);
    int t,n,s,j,i;
    long long ans = 0;
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        s = n/4;
        for(i=0;i<=s;i++){
            j = n - i*4;
            //cout<<C[j+1][i]<<" ";
            ans+=C[j+i][i];
        }
        cout<<np[ans]<<"\n";
    }
    return 0;
}

