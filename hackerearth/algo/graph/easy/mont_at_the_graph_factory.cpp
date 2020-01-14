#include <iostream>
using namespace std;

int main()
{
    int n,d;
    cin>>n;
    int p=n;
    int sum=0;
    while(p--){
    	cin>>d;
    	sum+=d;
    }
    if(sum==2*(n-1))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}
