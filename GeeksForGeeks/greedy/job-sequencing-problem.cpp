#include <bits/stdc++.h>
using namespace std;
class JSP{
    public:
        int dead;
        int profit;
        int j;
};
bool cmp(JSP a, JSP b){
    return a.profit > b.profit;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    JSP job[n+1];
	    int i;
	    for(i=0;i<n;i++){
	        cin>>job[i].j>>job[i].dead>>job[i].profit;
	    }
	    sort(job,job+n,cmp);
	    int res[n+1];
	    int slot[n+1];
	    for (int i=0; i<n; i++)
            slot[i] = 0;
        for(int i=0;i<n;i++){
            for(int j=min(n,job[i].dead)-1;j>=0;j--){
                if(slot[j]==0){
                    res[j] = i;
                    slot[j] = 1;
                    break;
                }
            }
        }
        int c=0,f=0;
        for (int i=0; i<n; i++)
            if (slot[i]){
                c++;
                f+=job[res[i]].profit;
            }
        cout<<c<<" "<<f<<"\n";
	}
	return 0;
}