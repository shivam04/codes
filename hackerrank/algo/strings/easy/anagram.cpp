#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int t,len,i,hash1[26],hash2[26],sum=0;
    char s[10001];
    scanf("%d",&t);
    while(t--)
        {
        sum=0;
        memset(hash1,0,sizeof(hash1));
        memset(hash2,0,sizeof(hash2));
        scanf("%s",s);
        len=strlen(s);
        if(len%2 != 0)
            printf("-1\n");
        else
        {
            for(i=0;i<len/2;i++)
                {
                hash1[s[i]-97]++;
            }
            for(i=len/2;i<len;i++)
                {
                hash2[s[i]-97]++;
            }
            for(i=0;i<26;i++)
                {
                sum+=abs(hash1[i]-hash2[i]);
            }
            printf("%d\n",sum/2);
        }
    }
    return 0;
}