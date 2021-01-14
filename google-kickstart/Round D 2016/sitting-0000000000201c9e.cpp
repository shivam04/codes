#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int tt=0;
    while(t--)
    {
        tt++;
        int row, colm;
        cin>>row>>colm;
        int a= row /3 + (row % 3 >= 1);
        int b= row /3 + (row % 3 >= 2); 
        
        int c= colm /3 * 2 + colm % 3;
        int res;
        if(colm <= 2)
        res = (a+b)*c;
        else if(row <= 2)
        res = (row* c);
        else if(colm % 3 ==0)
        res = (row * c);
        else if(colm % 3 ==2)
        res = a * c + (row-a)*(c-1);
        else if(colm % 3 ==1)
        res = (a+b) * c +(row-a-b) * (c-1);
        printf("Case #%d: %d\n", tt, res);
        
    }
}