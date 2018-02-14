#include <bits/stdc++.h>
using namespace std;
//vector<int> g[1005];
void initialize( int Arr[ ],int size[], int N)
{
    for(int i = 0; i <= N; i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root
    {
        i = Arr[ i ];
    }
    return i;
}
int cmpFunc(const void *a,const void *b){
	return *(int *)a - (*(int *)b);
}
void weightedunion(int Arr[ ],int size[ ],int A,int B,int N)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
       // size[A]  = 100000;
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
        //size[B]  = 100000;
    }
    int i;
    //int N = sizeof(Arr)/sizeof(int);
	int temp[N];
	int count=0;
	for(i=1;i<=N;i++)
	{
		if(Arr[i] == i)
		{
			temp[count]=size[i];
			count++;
		}
	}
	qsort(temp,count,sizeof(int),cmpFunc);
	for(i=0;i<count;i++)
		cout<<temp[i]<<" ";
 
	cout<<"\n";
}
int main()
{
    int n,m,i,a,b;
    cin>>n>>m;
    int arr[n+1];
    int size[n+1];
    initialize(arr,size,n);
    for(i=0;i<m;i++){
        cin>>a>>b;
        //g[a].push_back(b);
        weightedunion(arr,size,a,b,n);
        
    }
    
    return 0;
}
