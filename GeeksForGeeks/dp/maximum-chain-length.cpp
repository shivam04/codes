/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
bool cmp(struct val a,struct val b){
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,cmp);
    int mcl[n+1];
    int i,j;
    for(i=0;i<n;i++){
        mcl[i]=1;
    }
    int maxi = -1;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(p[i].first>p[j].second and mcl[i]<mcl[j]+1){
                mcl[i] = mcl[j]+1;
            }
        }
        //maxi = max(mcl[i],maxi);
    }
    for(i=0;i<n;i++){
        maxi = max(mcl[i],maxi);
    }
    return maxi;
}