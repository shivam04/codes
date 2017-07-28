#include <stdio.h>
int buy[10001];
void initialize(){
    int i;
    for(i=0;i<=10000;i++){
        buy[i]=0;
    }
}
int main()
{
    
    int t,e,x,y,j;
    scanf("%d",&t);
    int sum;
    while(t--){
        sum = 0;
        initialize();
        scanf("%d",&e);;
        //vector <int> a[10001];
        while(e--){
            scanf("%d %d",&x,&y);;
            buy[x]=1;
            buy[y]=1;
        }
        for(j=1;j<=10000;j++){
            sum+=buy[j];
        }
        printf("%d\n",sum);
    }
    return 0;
}
