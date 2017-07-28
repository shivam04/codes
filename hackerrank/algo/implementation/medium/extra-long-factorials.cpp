#include <stdio.h>
#define BASE 10
int main() 
{
	int i,j,t,n,m;
	unsigned int carry,k,a[160];
		
		scanf("%d",&n);
		a[0]=1;
			m=1;
		for(j=2;j<=n;j++)
		{
			carry=0;
			
			for(i=0;i<m;i++)
			{
				k=a[i]*j+carry;
				a[i]=k%BASE;
				carry=k/BASE;
			}
			while(carry!=0)
			{
				a[m++]=carry%BASE;
				carry=carry/BASE;
			}
		}
		printf("%d",a[m-1]);
	for(i=m-2;i>=0;i--)
		printf("%d",a[i]);
		printf("\n");
	return 0;
}
